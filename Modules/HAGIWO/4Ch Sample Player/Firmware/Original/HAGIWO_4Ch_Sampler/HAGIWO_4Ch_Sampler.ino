#include <FlashAsEEPROM_SAMD.h>//flash memory use as eeprom
#include "Periphery.h"
//OLED setting
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include <Wire.h>//for I2C
#include <avr/pgmspace.h>


// ディスプレイ変数の宣言
Adafruit_SSD1306 display(I2C_OLED_SCREEN_WIDTH, I2C_OLED_SCREEN_HEIGHT, &Wire, -1);
byte mode = 0;//display serect , sample 0-3 and amp 4-7 , pitch 8 , display 9 ,save 10
bool disp_ratch = 0;//1=display change , 0 = no change , for reduce i2c frequency.

bool disp_sw = 1; //1=display update on , 0 = no update for play sound.counter measure of delay by update display and reduce audio noise from display power supply
bool old_disp_sw = 0;
bool disp_font_set = 0;//1=font size big but have noise , 0 = font size small due to reduce noise.
bool disp_playback_show_set = 0; // 0=turn off the display while in playback mode, 1 = leave it on
bool disp_show = 0;
bool old_disp_show = 1;

//Buttons
int qt1 = 0;//read touch sensor ,use as select button
int qt2 = 0;//read touch sensor ,use as up button
int qt3 = 0;//read touch sensor ,use as down button
byte qt1_ratch = 0;//0=no signal,1=with signal,2=countermeasure of continuous signal
byte qt2_ratch = 0;
byte qt3_ratch = 0;

//sample setting
int slct_smpl1 = 0;
int slct_smpl2 = 0;
int slct_smpl3 = 0;
int slct_smpl4 = 0;

#include "realsamples.h"

byte pitch = 15;// 31usec = 1sec / 32kHz(sampling rate) ,Adjust by processing delay.

byte ch1_amp = 8;//sample default volume
byte ch2_amp = 8;
byte ch3_amp = 8;
byte ch4_amp = 8;

//ch1 setting
word ch1_i = 0;//Reference binary data of the sample to be played
bool ch1_ratch = 0;//0=no play sample , 1 = play sample
int ch1_sample = 0;//Referenced binary data of the sample to be played
bool ch1_in = 0;//external trig input
bool old_ch1_in = 0;//old external trig input

//ch2 setting
word ch2_i = 0;
bool ch2_ratch = 0;
int ch2_sample = 0;
bool ch2_in = 0;
bool old_ch2_in = 0;

//ch3 setting
word ch3_i = 0;
bool ch3_ratch = 0;
int ch3_sample = 0;
bool ch3_in = 0;
bool old_ch3_in = 0;

//ch4 setting
word ch4_i = 0;
bool ch4_ratch = 0;
int ch4_sample = 0;
bool ch4_in = 0;
bool old_ch4_in = 0;

void setup() {

 // ディスプレイの初期化
 display.begin(SSD1306_SWITCHCAPVCC, I2C_OLED_ADDRESS);
  display.clearDisplay();
  display.drawXBitmap(0, 0, Logo_bits, Logo_width, Logo_height, 1);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(45, 45);
  display.print("4Ch Sampler");
  display.display();
  delay(2000);
  display.clearDisplay();
 OLED_display();

 analogWriteResolution(10);
 analogReadResolution(10);
 pinMode(Pin_Ch1_In, INPUT_PULLDOWN);//pull-down resistance typ40kohm
 pinMode(Pin_Ch2_In, INPUT_PULLDOWN);
 pinMode(Pin_Ch3_In, INPUT_PULLDOWN);
 pinMode(Pin_Ch4_In, INPUT_PULLDOWN);
 
 pinMode(Pin_SW_Mode, INPUT_PULLUP); //for development

 //   Initialize Buttons
 pinMode(Pin_But_Up, INPUT_PULLUP);
 pinMode(Pin_But_Down, INPUT_PULLUP);
 pinMode(Pin_But_Select, INPUT_PULLUP);

 slct_smpl1 = 0;
 slct_smpl2 = 1;
 slct_smpl3 = 2;
 slct_smpl4 = 3;
 ch1_amp = 10;
 ch2_amp = 10;
 ch3_amp = 10;
 ch4_amp = 10;
 pitch = 15;
 OLED_display();
}

void loop() {
 old_disp_sw = disp_sw;
 disp_sw = !digitalRead(Pin_SW_Mode); 
 if (disp_playback_show_set == 0 && disp_sw == 0) {
  disp_show = 0;
 }
 else {
  disp_show = 1;
 }
 if (old_disp_show == 1 && disp_show == 0)
 {
    display.ssd1306_command(SSD1306_DISPLAYOFF);
 }
 if (old_disp_show == 0 && disp_show == 1)
 {
    display.ssd1306_command(SSD1306_DISPLAYON);
 }
 old_disp_show = disp_show;
 if (old_disp_sw == 0 && disp_sw == 1) { //switch on to off , mode 9 setting update
   //    mode = 0;
   if (disp_show == 1){
    OLED_display();    
   }
 }
 if (old_disp_sw == 1 && disp_sw == 0) { //switch off to on , mode 9 setting update
   //    mode = 0;
   ch1_ratch = 0;
   ch2_ratch = 0;
   ch3_ratch = 0;
   ch4_ratch = 0;   
   if (disp_show == 1){
    OLED_display();    
   }
 }
 if (disp_sw == 1 && ch1_ratch == 0 && ch2_ratch == 0 && ch3_ratch == 0 && ch4_ratch == 0 ) {
   //  touch sensor input
   qt1 = digitalRead(Pin_But_Select);
   qt2 = digitalRead(Pin_But_Up);
   qt3 = digitalRead(Pin_But_Down);

   if (qt1 < 1 && qt1_ratch == 0) {
     qt1_ratch = 1;
     disp_ratch = 1;
   }
   if (qt2 < 1 && qt2_ratch == 0) {
     qt2_ratch = 1;
     disp_ratch = 1;
   }
   if (qt3 < 1 && qt3_ratch == 0) {
     qt3_ratch = 1;
     disp_ratch = 1;
   }
   if (qt1 > 0) {
     qt1_ratch = 0;
   }
   if (qt2 > 0) {
     qt2_ratch = 0;
   }
   if (qt3 > 0) {
     qt3_ratch = 0;
   }

   if (qt1_ratch == 1) {
     mode ++;
     qt1_ratch = 2;
     if (mode >= 11) {
       mode = 0;
     }
     else if (mode < 0) {
       mode = 10;
     }
   }

   //select sample
   if (mode == 0) {  //select CH1 sample
     if (qt2_ratch == 1) {
       slct_smpl1 --;
       qt2_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       slct_smpl1 ++;
       qt3_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     if (slct_smpl1 >= 18) {
       slct_smpl1 = 0;
     }
     else if (slct_smpl1 < 0) {
       slct_smpl1 = 17;
     }
   }

   else if (mode == 1) {  //select CH2 sample
     if (qt2_ratch == 1) {
       slct_smpl2 --;
       qt2_ratch = 2;
       ch2_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       slct_smpl2 ++;
       qt3_ratch = 2;
       ch2_ratch = 1;//one shot sample play
     }
     if (slct_smpl2 >= 18) {
       slct_smpl2 = 0;
     }
     else if (slct_smpl2 < 0) {
       slct_smpl2 = 17;
     }
   }

   else if (mode == 2) {  //select CH3 sample
     if (qt2_ratch == 1) {
       slct_smpl3 --;
       qt2_ratch = 2;
       ch3_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       slct_smpl3 ++;
       qt3_ratch = 2;
       ch3_ratch = 1;//one shot sample play
     }
     if (slct_smpl3 >= 18) {
       slct_smpl3 = 0;
     }
     else if (slct_smpl3 < 0) {
       slct_smpl3 = 17;
     }
   }

   else if (mode == 3) {  //select CH4 sample
     if (qt2_ratch == 1) {
       slct_smpl4 --;
       qt2_ratch = 2;
       ch4_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       slct_smpl4 ++;
       qt3_ratch = 2;
       ch4_ratch = 1;//one shot sample play
     }
     if (slct_smpl4 >= 18) {
       slct_smpl4 = 0;
     }
     else if (slct_smpl4 < 0) {
       slct_smpl4 = 17;
     }
   }

   //----------------control each ch volume-----------------------
   if (mode == 4) {  //select CH1 sample
     if (qt2_ratch == 1) {
       ch1_amp --;
       qt2_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       ch1_amp ++;
       qt3_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     if (ch1_amp >= 10) {
       ch1_amp = 10;
     }
     else if (ch1_amp < 1) {
       ch1_amp = 1;
     }
   }

   else if (mode == 5) {  //change CH2 volume
     if (qt2_ratch == 1) {
       ch2_amp --;
       qt2_ratch = 2;
       ch2_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       ch2_amp ++;
       qt3_ratch = 2;
       ch2_ratch = 1;//one shot sample play
     }
     if (ch2_amp >= 10) {
       ch2_amp = 10;
     }
     else if (ch2_amp < 1) {
       ch2_amp = 1;
     }
   }

   else if (mode == 6) {  //change CH3 volume
     if (qt2_ratch == 1) {
       ch3_amp --;
       qt2_ratch = 2;
       ch3_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       ch3_amp ++;
       qt3_ratch = 2;
       ch3_ratch = 1;//one shot sample play
     }
     if (ch3_amp >= 10) {
       ch3_amp = 10;
     }
     else if (ch3_amp < 1) {
       ch1_amp = 1;
     }
   }

   else if (mode == 7) {  //change CH4 volume
     if (qt2_ratch == 1) {
       ch4_amp --;
       qt2_ratch = 2;
       ch4_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       ch4_amp ++;
       qt3_ratch = 2;
       ch4_ratch = 1;//one shot sample play
     }
     if (ch4_amp >= 10) {
       ch4_amp = 10;
     }
     else if (ch4_amp < 1) {
       ch4_amp = 1;
     }
   }

   //----------------pitch control and display andSAVE-----------------------
   else if (mode == 8) {  //pitch control
     if (qt2_ratch == 1) {
       pitch --;
       qt2_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     else if (qt3_ratch == 1) {
       pitch ++;
       qt3_ratch = 2;
       ch1_ratch = 1;//one shot sample play
     }
     if (pitch >= 52) {
       pitch = 52;
     }
     else if (pitch < 5) {
       pitch = 5;
     }
   }

   else if (mode == 9) {  //save
     if (qt2_ratch == 1) {
       qt2_ratch = 2;
       disp_font_set = 1;
     }
     else if (qt3_ratch == 1) {
       qt3_ratch = 2;
       disp_font_set = 0;
     }
   }

   else if (mode == 10) {  //save
     if (qt2_ratch == 1) {
       qt2_ratch = 2;
       save();
     }
     else if (qt3_ratch == 1) {
       qt3_ratch = 2;
       save();
     }
   }
   disp_ratch = 1;

   if (  disp_ratch == 1) {
     OLED_display();
     disp_ratch = 0;
     //delay(100);//countermeasure of touch sensor continuous input
   }
   if (ch1_ratch == 1 || ch2_ratch == 1 || ch3_ratch == 1 || ch4_ratch == 1 ) {
     soundout();
   }
 }


 else if (disp_sw == 0) {
   //----------------signal input--------------------------
   old_ch1_in = ch1_in;
   old_ch2_in = ch2_in;
   old_ch3_in = ch3_in;
   old_ch4_in = ch4_in;

   ch1_in = digitalRead(1);
   ch2_in = digitalRead(2);
   ch3_in = digitalRead(3);
   ch4_in = digitalRead(6);
   soundout();
 }

 else {
   soundout();
 }
}

void soundout() {

 if (ch1_i >= 8000) {
   ch1_i = 0;
   ch1_ratch = 0;
   ch1_sample = 127;
 }

 if (ch2_i >= 8000) {
   ch2_i = 0;
   ch2_ratch = 0;
   ch2_sample = 127;
 }

 if (ch3_i >= 8000) {
   ch3_i = 0;
   ch3_ratch = 0;
   ch3_sample = 127;
 }

 if (ch4_i >= 8000) {
   ch4_i = 0;
   ch4_ratch = 0;
   ch4_sample = 127;
 }


 if (old_ch1_in == 0 && ch1_in == 1) {
   ch1_ratch = 1;
   ch1_i = 0;
 }
 if (old_ch2_in == 0 && ch2_in == 1) {
   ch2_ratch = 1;
   ch2_i = 0;
 }
 if (old_ch3_in == 0 && ch3_in == 1) {
   ch3_ratch = 1;
   ch3_i = 0;
 }
 if (old_ch4_in == 0 && ch4_in == 1) {
   ch4_ratch = 1;
   ch4_i = 0;
 }


 if (ch1_ratch == 1) {
   ch1_i ++;
 }
 if (ch2_ratch == 1) {
   ch2_i ++;
 }
 if (ch3_ratch == 1) {
   ch3_i ++;
 }
 if (ch4_ratch == 1) {
   ch4_i ++;
 }

 //Read sample data and volume setting.
 ch1_sample = ((pgm_read_byte(&(smpl[slct_smpl1][ch1_i])) - 127) * ch1_amp / 10 * 4);
 ch2_sample = ((pgm_read_byte(&(smpl[slct_smpl2][ch2_i])) - 127) * ch2_amp / 10 * 4);
 ch3_sample = ((pgm_read_byte(&(smpl[slct_smpl3][ch3_i])) - 127) * ch3_amp / 10 * 4);
 ch4_sample = ((pgm_read_byte(&(smpl[slct_smpl4][ch4_i])) - 127) * ch4_amp / 10 * 4);

 if (ch1_ratch == 1 || ch2_ratch == 1 || ch3_ratch == 1 || ch4_ratch == 1 ) {
   int sampleout = ch1_sample + ch2_sample + ch3_sample + ch4_sample + 511;
   sampleout = constrain(sampleout, 0, 1023);
   analogWrite(Pin_DAC, sampleout);
   delayMicroseconds(pitch);
   }
}

void save() {//save setting data to flash memory
 delay(100);
 EEPROM.write(1, slct_smpl1);
 EEPROM.write(2, slct_smpl2);
 EEPROM.write(3, slct_smpl3);
 EEPROM.write(4, slct_smpl4);
 EEPROM.write(5, ch1_amp);
 EEPROM.write(6, ch2_amp);
 EEPROM.write(7, ch3_amp);
 EEPROM.write(8, ch4_amp);
 EEPROM.write(9, pitch);
 EEPROM.commit();

 display.clearDisplay();  // clear display
 display.setTextSize(disp_font_set + 1);  
 if (disp_sw == 1) {
   display.setTextSize(2);  
 }
 display.setTextColor(BLACK, WHITE);
 display.setCursor(0, 32);  
 display.print("SAVED");
 display.display();
 delay(1000);
}

void OLED_display() {
 display.clearDisplay();  
 display.setTextSize(disp_font_set + 1);  
 if (disp_sw == 1) {
   display.setTextSize(2);  
 }
 display.setTextColor(WHITE); 

 if ( mode <= 7) {
   //sample display
   display.setCursor(0, 0);  
   display.print(smpl_name[slct_smpl1]);
   display.setCursor(0, 16);  
   display.print(smpl_name[slct_smpl2]);
   display.setCursor(0, 32);  
   display.print(smpl_name[slct_smpl3]);
   display.setCursor(0, 48);  
   display.print(smpl_name[slct_smpl4]);

   //amp display
   display.drawRect(95, 0, ch1_amp * 3, 15, WHITE);
   display.drawRect(95, 16, ch2_amp * 3, 15, WHITE);
   display.drawRect(95, 32, ch3_amp * 3, 15, WHITE);
   display.drawRect(95, 48, ch4_amp * 3, 15, WHITE);

   //mode display
   if (mode < 4 && disp_sw == 1) {
     display.drawTriangle(92, 2 + mode * 16, 92, 10 + mode * 16, 86, 6 + mode * 16, WHITE);
   }
   else if (mode >= 4 && disp_sw == 1) {
     display.drawTriangle(86, 2 + (mode - 4) * 16, 86, 10 + (mode - 4) * 16, 92, 6 + (mode - 4) * 16, WHITE);
   }
 }

 else if (mode >= 8) {
   display.setCursor(0, 0);  
   display.print("PITCH");
   display.setCursor(70, 0);  
   display.print(pitch);
   display.setCursor(0, 16);  
   display.print("NOISE");
   display.setCursor(70, 16);  
   if (disp_font_set == 1) {
     display.print("MID");
   }
   else if (disp_font_set == 0) {
     display.print("LOW");
   }
   display.setCursor(0, 32);  
   display.print("SAVE");
   display.drawTriangle(114, 2 + (mode - 8) * 16, 114, 10 + (mode - 8) * 16, 108, 6 + (mode - 8) * 16, WHITE);

 }
 display.display();
}
