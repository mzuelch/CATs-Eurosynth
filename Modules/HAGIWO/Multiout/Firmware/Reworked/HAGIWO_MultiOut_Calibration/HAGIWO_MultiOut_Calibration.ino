#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "Periphery.h"
Adafruit_SSD1306 display(I2C_OLED_SCREEN_WIDTH, I2C_OLED_SCREEN_HEIGHT, &Wire, -1);
#include <Wire.h>
//Rotery encoder setting
#include <EncoderButton.h>
EncoderButton myEnc(Pin_Enc_B, Pin_Enc_A, Pin_Enc_SW);//rotery encoder library setting
boolean Okay;

void onEncoderDoubleClick(EncoderButton& eb) {
  Okay = true;
}
void CalibrateOutputs() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Disconnect all cables");
  display.setCursor(1, 16);
  display.print("Doubleclick Encoder");
  display.setCursor(1, 30);
  display.print("to continue");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  Wire.beginTransmission(I2C_MCP_1);
  Wire.write((3276 >> 8) & 0x0F);
  Wire.write(3276);
  Wire.endTransmission();
  Wire.beginTransmission(I2C_MCP_2);
  Wire.write((3276 >> 8) & 0x0F);
  Wire.write(3276);
  Wire.endTransmission();
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Adjust Trimmers for");
  display.setCursor(1, 14);
  display.print("exactly 4.000V");
  display.setCursor(1, 32);
  display.print("Doubleclick Encoder");
  display.setCursor(1, 46);
  display.print("to continue");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  Wire.beginTransmission(I2C_MCP_1);
  Wire.write((0 >> 8) & 0x0F);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(I2C_MCP_2);
  Wire.write((0 >> 8) & 0x0F);
  Wire.write(0);
  Wire.endTransmission();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Disconnect all cables");
  display.setCursor(1, 16);
  display.print("Doubleclick Encoder");
  display.setCursor(1, 30);
  display.print("to continue");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Running...");
  display.display();
  const int Sample_length = 64;
  int Sample_Ch1[Sample_length];
  int Sample_Ch2[Sample_length];
  double Sample_Sum_Ch1 = 0.0;
  double Sample_Sum_Ch2 = 0.0;
  for (int i = 0; i<Sample_length; i++) {
    Sample_Ch1[i] = analogRead(Pin_Ch1_In);
    Sample_Ch2[i] = analogRead(Pin_Ch2_In);
    delay(100);
    Sample_Sum_Ch1 += double(Sample_Ch1[i]);
    Sample_Sum_Ch2 += double(Sample_Ch2[i]);
  }
  Sample_Sum_Ch1 = Sample_Sum_Ch1/double(Sample_length);
  Sample_Sum_Ch2 = Sample_Sum_Ch2/double(Sample_length);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("AD_CH1_calib_b = ");
  display.setCursor(1, 14);
  display.print(-Sample_Sum_Ch1,4);
  double AD_CH1_calib_b = -Sample_Sum_Ch1;
  display.setCursor(1, 30);
  display.print("AD_CH2_calib_b = ");
  display.setCursor(1, 43);
  display.print(-Sample_Sum_Ch2,4);
  double AD_CH2_calib_b = -Sample_Sum_Ch2;
  display.setCursor(1, 57);
  display.print("Doubleclick Encoder");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  Wire.beginTransmission(I2C_MCP_1);
  Wire.write((3276 >> 8) & 0x0F);
  Wire.write(3276);
  Wire.endTransmission();
  Wire.beginTransmission(I2C_MCP_2);
  Wire.write((3276 >> 8) & 0x0F);
  Wire.write(3276);
  Wire.endTransmission();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Connect Ch1 In");
  display.setCursor(1, 14);
  display.print("and Ch1 Out");
  display.setCursor(1, 32);
  display.print("Doubleclick Encoder");
  display.setCursor(1, 46);
  display.print("to continue");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.setCursor(1, 1);
  display.print("Connect Ch2 In");
  display.setCursor(1, 14);
  display.print("and Ch2 Out");
  display.setCursor(1, 32);
  display.print("Doubleclick Encoder");
  display.setCursor(1, 46);
  display.print("to continue");
  display.display();
  Okay=false;
  while(!Okay) {
    myEnc.update();
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("Running...");
  display.display();
  Sample_Sum_Ch1 = 0.0;
  Sample_Sum_Ch2 = 0.0;
  for (int i = 0; i<Sample_length; i++) {
    Sample_Ch1[i] = analogRead(Pin_Ch1_In);
    Sample_Ch2[i] = analogRead(Pin_Ch2_In);
    delay(100);
    Sample_Sum_Ch1 += double(Sample_Ch1[i]);
    Sample_Sum_Ch2 += double(Sample_Ch2[i]);
  }
  Sample_Sum_Ch1 = Sample_Sum_Ch1/double(Sample_length);
  Sample_Sum_Ch2 = Sample_Sum_Ch2/double(Sample_length);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(1, 1);
  display.print("AD_CH1_calib_m = ");
  display.setCursor(1, 14);
  display.print(3276.0/(Sample_Sum_Ch1+AD_CH1_calib_b),4);
  display.setCursor(1, 30);
  display.print("AD_CH2_calib_m = ");
  display.setCursor(1, 43);
  display.print(3276.0/(Sample_Sum_Ch2+AD_CH2_calib_b),4);

  display.display();
}
void setup() {
  // put your setup code here, to run once:
  analogWriteResolution(10);
  analogReadResolution(12);
  pinMode(Pin_Trg_In, INPUT_PULLDOWN); //CLK in
  pinMode(Pin_Ch1_In, INPUT);//IN1
  pinMode(Pin_Ch2_In, INPUT);//IN2
  pinMode(Pin_Ch1_Gate, OUTPUT); //CH1 EG out
  pinMode(Pin_Ch2_Gate, OUTPUT); //CH2 EG out
  
  // Encoder Initialize
  //myEnc.setEncoderHandler(onEncoder);
  myEnc.setDoubleClickHandler(onEncoderDoubleClick);
  
  display.begin(SSD1306_SWITCHCAPVCC, I2C_OLED_ADDRESS);
  display.clearDisplay();
  display.drawXBitmap(0, 0, Logo_bits, Logo_width, Logo_height, 1);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(45, 45);
  display.print("Calibration");
  display.display();
  delay(2000);
  display.clearDisplay();
  //I2C connect
  Wire.begin();
  Wire.setClock(3400000);
  CalibrateOutputs();
}

void loop() {

}
