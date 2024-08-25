#include <avr/io.h>//for fast PWM
#include "fix_fft.h"//spectrum analyze
#include <EEPROM.h>

//OLED display setting
#include <SPI.h>//for OLED display
#include <Adafruit_GFX.h>//for OLED display
#include <Adafruit_SSD1306.h> //for OLED display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                        OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
//EEPROM
#define ENCODER_DIR_ADDR 0  // EEPROM address to store the encoder direction
#define MENUTIMER_DIR_ADDR 1  // EEPROM address to store the menuTimer direction

//rotary encoder setting
#define  ENCODER_OPTIMIZE_INTERRUPTS //contermeasure of rotery encoder noise
#include <Encoder.h>
Encoder myEnc(2, 4);//rotery encoder digitalRead pin
float oldPosition  = -999;//rotery encoder counter
float newPosition = -999;


byte mode = 1;//1=low freq oscilo , 2=high freq oscilo , 3 = mid freq oscilo with external trig , 4 = spectrum analyze
byte old_mode = 1;//for initial setting when mode change.
byte param_select = 0;
byte param = 0;
byte param1 = 1;
bool param1_select = 0;
byte param2 = 1;
bool param2_select = 0;
int rfrs = 0;//display refresh rate

bool trig = 0;//external trig
bool old_trig = 0;//external trig , OFF -> ON detect
bool old_SW = 0;//push sw, OFF -> ON detect
bool SW = 0;//push sw

unsigned long trigTimer = 0;
unsigned long hideTimer = 0;//hide parameter count
bool hide = 0; //1=hide,0=not hide

char data[128], im[128] , cv[128]; //data and im are used for spectrum , cv is used for oscilo.


bool encoderPressed = false;

//Global Configs
bool secretMenuActive = false;
unsigned long enterPressStartTime = 0; // Timer for entering the secret menu
unsigned long exitPressStartTime = 0;  // Timer for exiting the secret menu
byte secretMenuOption = 1; // 1 for encoderDirection, 2 for menuTimer
unsigned int menuTimer = 5; // Default value for menuTimer, set to 100
int encoderDirection = 1; // 1 for normal, -1 for reversed



void setup() {

  // Load the saved encoder direction from EEPROM
  EEPROM.get(ENCODER_DIR_ADDR, encoderDirection);
  delay(10);
  if (encoderDirection != 1 && encoderDirection != -1) {
    encoderDirection = 1;  // Default to normal direction if EEPROM contains invalid data
  }
  
  EEPROM.get(MENUTIMER_DIR_ADDR, menuTimer);
  delay(10);
  if (menuTimer < 1 || menuTimer > 30) {
    menuTimer = 5;  // Default to 5 if menuTimer is invalid
  }

 //display setting
 display.begin(SSD1306_SWITCHCAPVCC);
 display.clearDisplay();
 display.setTextSize(0);
 display.setTextColor(WHITE);
 analogReference(DEFAULT);

 //pin mode setting
 pinMode(3, OUTPUT) ;//offset voltage
 pinMode(5, INPUT_PULLUP);//push sw
 pinMode(6, INPUT) ;//input is high impedance -> no active 2pole filter , output is active 2pole filter
 pinMode(7, INPUT); //external triger detect

 //fast pwm setting
 TCCR2B &= B11111000;
 TCCR2B |= B00000001;

 //fast ADC setting
 ADCSRA = ADCSRA & 0xf8;//fast ADC *8 speed
 ADCSRA = ADCSRA | 0x04;//fast ADC *8 speed
 
};

void loop() {

  old_SW = SW;
  old_mode = mode; 
  SW = digitalRead(5);

   // Handle entering the secret menu
    if (SW == LOW && !encoderPressed && !secretMenuActive) { // Button just pressed
        encoderPressed = true;
        enterPressStartTime = millis(); // Start timing the press
    } else if (SW == HIGH && encoderPressed && !secretMenuActive) { // Button released
        encoderPressed = false;
    }

    if (encoderPressed && millis() - enterPressStartTime >= 3000 && !secretMenuActive) {
        // Enter the secret menu after holding for 3 seconds
        secretMenuActive = true;
        enterPressStartTime = 0;
        encoderPressed = false; // Reset press state
        secretMenuOption = 1; // Reset to first option
        oldPosition = newPosition = myEnc.read(); // Reset encoder position
    }

    if (secretMenuActive) {
        int newDirection = encoderDirection;
        newPosition = myEnc.read();

        // Check if the encoder was turned
        if (newPosition > oldPosition) {
            oldPosition = newPosition;
            if (secretMenuOption == 1) {
                newDirection = 1; // Normal direction
            } else if (secretMenuOption == 2) {
                menuTimer += encoderDirection;
                menuTimer = constrain(menuTimer, 1, 60);
            }
        } else if (newPosition < oldPosition) {
            oldPosition = newPosition;
            if (secretMenuOption == 1) {
                newDirection = -1; // Reversed direction
            } else if (secretMenuOption == 2) {
                menuTimer -= encoderDirection;
                menuTimer = constrain(menuTimer, 1, 60);
            }
        }

        // Update encoder direction if changed
        if (newDirection != encoderDirection) {
            encoderDirection = newDirection;
        }

        // Display the secret menu
        display.clearDisplay();
        display.setCursor(0, 0);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.println("             MENU");
        display.setTextColor(secretMenuOption == 1 ? BLACK : WHITE, secretMenuOption == 1 ? WHITE : BLACK);
        display.println("1. Enc. Direction:");
        display.setTextColor(WHITE);
        display.println(encoderDirection == 1 ? "Normal" : "Reversed");
        display.println("");
        display.setTextColor(secretMenuOption == 2 ? BLACK : WHITE, secretMenuOption == 2 ? WHITE : BLACK);
        display.println("2. Menu Timer:");
        display.setTextColor(WHITE);

        display.println(menuTimer);
        display.display();

        // Handle encoder button press within secret menu
        if (SW == LOW && !encoderPressed) {
            encoderPressed = true;
            exitPressStartTime = millis(); // Start timing the press for exit
        } else if (SW == HIGH && encoderPressed) {
            if (millis() - exitPressStartTime < 3000) {
                // Short press: switch between encoderDirection and menuTimer
                secretMenuOption = secretMenuOption == 1 ? 2 : 1;
            }
            encoderPressed = false;
            exitPressStartTime = 0;
        }

        // Check if button has been held down for 3 seconds to exit the secret menu
        if (encoderPressed && millis() - exitPressStartTime >= 3000) {
            EEPROM.put(ENCODER_DIR_ADDR, encoderDirection); // Save the new direction to EEPROM
            delay(50);
            EEPROM.put(MENUTIMER_DIR_ADDR, menuTimer); // Save the new direction to EEPROM
            delay(50);
            secretMenuActive = false; // Exit the secret menu
            display.clearDisplay();
            display.display(); // Clear the screen or return to the main menu display
            encoderPressed = false;
            exitPressStartTime = 0;
            delay(500); // Debounce delay
        }

  } else {
  
  //START OF MAIN LOGIC

  // Use encoder in the chosen direction
  newPosition = encoderDirection * myEnc.read();

 //select mode by push sw
 if (old_SW == 0 && SW == 1 && param_select == param) {
   param_select = 0;
   hideTimer = millis();
 }
 else if (old_SW == 0 && SW == 1 && param == 1) {
   param_select = param;
   hideTimer = millis();
 }
 else   if (old_SW == 0 && SW == 1 && param == 2) {
   param_select = param;
   hideTimer = millis();
 }
 else   if (old_SW == 0 && SW == 1 && param == 3) {
   param_select = param;
   hideTimer = millis();
 }
 mode = constrain(mode, 1, 4);
 param = constrain(param, 1, 3);

 //rotery encoder input
 newPosition = encoderDirection * myEnc.read();
 
 if ( (newPosition - 3) / 4  > oldPosition / 4) {
   oldPosition = newPosition;
   hideTimer = millis();
   switch (param_select) {
     case 0:
       param ++;
       break;

     case 1:
       mode ++;
       break;

     case 2:
       param1 ++;
       break;

     case 3:
       param2 ++;
       break;
   }
 }

 else if ( (newPosition + 3) / 4  < oldPosition / 4 ) {
   oldPosition = newPosition;
   hideTimer = millis();
   switch (param_select) {
     case 0:
       param --;
       break;

     case 1:
       mode --;
       break;

     case 2:
       param1 --;
       break;

     case 3:
       param2 --;
       break;

   }
 }

 //initial settin when mode change.
 if (old_mode != mode) {
   switch (mode) {
     case 1:
       param1 = 2; //time
       param2 = 1; //offset
       pinMode(6, INPUT);//no active 2pole filter
       analogWrite(3, 0); //offset = 0V
       ADCSRA = ADCSRA & 0xf8;//fast ADC *8 speed
       ADCSRA = ADCSRA | 0x04;//fast ADC *8 speed
       break;

     case 2:
       param1 = 3; //time
       param2 = 3; //offset
       analogWrite(3, 127); //offset = 2.5V
       pinMode(6, INPUT);//no active 2pole filter
       ADCSRA = ADCSRA & 0xf8;//fast ADC *8 speed
       ADCSRA = ADCSRA | 0x04;//fast ADC *8 speed
       break;

     case 3:
       param1 = 2; //time
       analogWrite(3, 127); //offset = 2.5V
       pinMode(6, INPUT);//no active 2pole filter
       ADCSRA = ADCSRA & 0xf8;//fast ADC *8 speed
       ADCSRA = ADCSRA | 0x04;//fast ADC *8 speed
       break;

     case 4:
       param1 = 2; //high freq amp
       param2 = 3; //noise filter
       analogWrite(3, 127); //offset = 2.5V
       pinMode(6, OUTPUT);//active 2pole filter
       digitalWrite(6, LOW);//active 2pole filter
       ADCSRA = ADCSRA & 0xf8;//standard ADC speed
       ADCSRA = ADCSRA | 0x07;//standard ADC speed
       break;
   }
 }

 //OLED parameter hide while no operation
 if ( hideTimer + (menuTimer * 1000) >= millis() ) {//
   hide = 1;
 }
 else {
   hide = 0;
 }

 //LFO mode--------------------------------------------------------------------------------------------
if (mode == 1) {
   param = constrain(param, 1, 3);
   param1 = constrain(param1, 1, 8);
   param2 = constrain(param2, 1, 8);

   display.clearDisplay();

   //store data
   for (int i = 126 / (9 - param1); i >= 0; i--) {
     display.drawLine(127 - (i * (9 - param1)) , 63 - cv[i] - (param2 - 1) * 4, 127 - (i + 1) * (9 - param1) , 63 - cv[(i + 1 )] - (param2 - 1) * 4, WHITE); //right to left
     cv[i + 1] = cv[i];
     if (i == 0) {
       cv[0] = analogRead(0) / 16;
     }
   }

   //display
   if (hide == 1) {
     display.drawLine((param - 1) * 42, 8,   (param - 1) * 42 + 36, 8, WHITE);

     display.setTextColor(WHITE);
     if (param_select == 1) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(0, 0);
     display.print("Mode:");
     display.setCursor(30, 0);
     display.print(mode);

     display.setTextColor(WHITE);
     if (param_select == 2) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(42, 0);
     display.print("Time:");
     display.setCursor(72, 0);
     display.print(param1);

     display.setTextColor(WHITE);
     if (param_select == 3) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(84, 0);
     display.print("Offs:");
     display.setCursor(114, 0);
     display.print(param2);
   }
 }



 //wave mode---------------------------------------------------------------------------------------------
 else if (mode == 2) {
   param = constrain(param, 1, 3);
   param1 = constrain(param1, 1, 8);
   param2 = constrain(param2, 1, 6);

   //store data
   if (param1 > 5) {//for mid frequency
     for (int i = 127 ; i >= 0; i--) {
       cv[i] = analogRead(0) / 16;
       delayMicroseconds((param1 - 5) * 20);
     }
     rfrs++;
     if (rfrs >= (param2 - 1) * 2) {
       rfrs = 0;
       display.clearDisplay();
       for (int i = 127 ; i >= 1; i--) {
         display.drawLine(127-i , 63 - cv[i - 1], 127-(i + 1)  , 63 - cv[(i)], WHITE);
       }
     }
   }

   else if (param1 <= 5) {//for high frequency
     for (int i = 127 / (6 - param1); i >= 0; i--) {
       cv[i] = analogRead(0) / 16;
     }
     rfrs++;
     if (rfrs >= (param2 - 1) * 2) {
       rfrs = 0;
       display.clearDisplay();
       for (int i = 127 / (6 - param1); i >= 1; i--) {
         display.drawLine(127-i * (6 - param1), 63 - cv[i - 1], 127-(i + 1) * (6 - param1)  , 63 - cv[(i)], WHITE);
       }
     }
   }

   //display
   if (hide == 1) {
     display.drawLine((param - 1) * 42, 8,   (param - 1) * 42 + 36, 8, WHITE);
     display.setTextColor(WHITE);
     if (param_select == 1) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(0, 0);
     display.print("Mode:");
     display.setCursor(30, 0);
     display.print(mode);

     display.setTextColor(WHITE);
     if (param_select == 2) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(42, 0);
     display.print("Time:");
     display.setCursor(72, 0);
     display.print(param1);

     display.setTextColor(WHITE);
     if (param_select == 3) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(84, 0);
     display.print("Rfrs:");
     display.setCursor(114, 0);
     display.print(param2);
   }
 }

//shot mode---------------------------------------------------------------------------------------------
 else if (mode == 3) {
   param = constrain(param, 1, 2);
   param1 = constrain(param1, 1, 4);
   old_trig = trig;
   trig = digitalRead(7);

   //    trig detect
   if (old_trig == 0 && trig == 1  ) {
     for (int i = 10 ; i <= 127; i++) {
       cv[i] = analogRead(0) / 16;
       delayMicroseconds(100000 * param1);//100000 is magic number
     }
     for (int i = 0 ; i < 10; i++) {
       cv[i] = 32;
     }
   }

   display.clearDisplay();
   for (int i = 126 ; i >= 1; i--) {
     display.drawLine(i , 63 - cv[i], (i + 1)  , 63 - cv[(i + 1)], WHITE);
   }

   //display
   if (hide == 1) {
     display.drawLine((param - 1) * 42, 8,   (param - 1) * 42 + 36, 8, WHITE);
     display.setTextColor(WHITE);
     if (param_select == 1) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(0, 0);
     display.print("Mode:");
     display.setCursor(30, 0);
     display.print(mode);

     display.setTextColor(WHITE);
     if (param_select == 2) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(42, 0);
     display.print("Time:");
     display.setCursor(72, 0);
     display.print(param1);
     display.setTextColor(WHITE);
     if (trig == 1) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(84, 0);
     display.print("TRIG");
   }
 }

 //spectrum analyze mode---------------------------------------------------------------------------------------------
 else if (mode == 4) {
   param = constrain(param, 1, 3);
   param1 = constrain(param1, 1, 4);//high freq sence
   param2 = constrain(param2, 1, 8);//noise filter

   for (byte i = 0; i < 128; i++) {
     int spec = analogRead(0);
     data[i] = spec / 4 - 128;
     im[i] = 0;
   };
   fix_fft(data, im, 7, 0);
   display.clearDisplay();
   for (byte i = 0; i < 64; i++) {
     int level = sqrt(data[i] * data[i] + im[i] * im[i]);;
     if (level >= param2) {
       display.fillRect(i * 2, 63 - (level + i * (param1 - 1) / 8), 2, (level + i * (param1 - 1) / 8), WHITE); // i * (param1 - 1) / 8 is high freq amp
     }
   }

   //display
   if (hide == 1) {
     display.drawLine((param - 1) * 42, 8,   (param - 1) * 42 + 36, 8, WHITE);
     display.setTextColor(WHITE);
     if (param_select == 1) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(0, 0);
     display.print("Mode:");
     display.setCursor(30, 0);
     display.print(mode);

     display.setTextColor(WHITE);
     if (param_select == 2) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(42, 0);
     display.print("High:");
     display.setCursor(72, 0);
     display.print(param1);

     display.setTextColor(WHITE);
     if (param_select == 3) {
       display.setTextColor(BLACK, WHITE);
     }
     display.setCursor(84, 0);
     display.print("Filt:");
     display.setCursor(114, 0);
     display.print(param2);
   }
 }

 display.display();
}
};
