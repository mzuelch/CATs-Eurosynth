#include  <avr/io.h>//for fast PWM

// This is the Bezier curve random CV generator code from HAGIWO adapted for the Sync LFO mzuelch published on Github
// More info here: https://note.com/solder_state/n/n39aacefd73a3 and https://www.youtube.com/watch?v=yJ8VUiZf6Yg
// 
// Pot 0 -> frequency
// Pot 1 -> curve
// pot 2 -> frequency variation
// Pot 3 -> Level 



#define cvOutput 10
#define trigInput 3 // digital in
#define freqPot 0
#define curvePot 1
#define levelPot 3
#define devPot 5


bool ext_pulse = 0;//0=no external in
bool old_ext_pulse = 0;
int i = 0;
int start_val = 0;//Bezier Curve Starting Point
int end_val = 255;//Bezier Curve end Point
float old_wait = 0;
float wait = 0;//Bezier curve x-axis (time)
float bz_val = 0;//Bezier curve y-axis (voltage)
int  dev, level, curve, freq;
long timer = 0;//
long timer1 = 0;//analog read interval
float x[256];//Bezier Curve Calculation Tables

int freq_rnd = 501;
int freq_dev = 40;
int chance[32] = {5, 12, 21, 33, 48, 67, 90, 118, 151, 189, 232, 279, 331, 386, 443, 501, 559, 616, 671, 723, 770, 813, 851, 884, 912, 935, 954, 969, 981, 990, 997, 1000};//normal distribution table
int freq_err[32] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 22, 24, 26, 28, 30, 33, 36, 40, 46, 52, 58, 64, 70, 76, 82, 90, 98, 110, 122, 136, 148};//Frequency Variation

void setup()
{
 for (int j = 0; j < 255; j++) {//Preparation of Bezier Curve Calculation Tables
   x[j] = j * 0.003921; //j/255
 }
 pinMode(cvOutput, OUTPUT); //CV output
 pinMode(trigInput, INPUT); // trigger input
 timer = micros();
 timer1 = millis();
 // 9,10pin pwm setting
 TCCR1B &= B11111000;
 TCCR1B |= B00000001;
 delay(50);
}

void loop()
{
 // todo gate / trigger input for ?
 old_ext_pulse = ext_pulse;
 ext_pulse = digitalRead(trigInput);
 
 if(timer1 +50 < millis()){
 //freq = min(511,(analogRead(0) / 2 + analogRead(7) / 2)) * freq_dev;
 // no cv input 
 freq = min(511,(analogRead(freqPot) / 2)) * freq_dev;
 //curve = min(255,(analogRead(1) / 4 + analogRead(6) / 4));
 // no cv input
 curve = min(255,(analogRead(curvePot) / 4));
 level = analogRead(levelPot) / 4;
 timer1 = millis();
 }

 if (timer + (wait - old_wait)  <= micros()) {
   old_wait = wait;
   i++;

   if (i >= 255) {//Recalculation of target voltage values
     i = 0;
     start_val = end_val;
     end_val = random(0, 255);
     change_freq_error();
   }

   //Bezier Curve Calculations
   wait = 3 * pow((1 - x[i]), 2) * x[i] * curve + 3 * (1 - x[i]) * pow(x[i], 2) * (255 - curve) + pow(x[i], 3) * 255;
   wait = 1+wait * freq*2;
   bz_val = pow((1 - x[i]), 3) * start_val + 3 * pow((1 - x[i]), 2) * x[i] * start_val + 3 * (1 - x[i]) * pow(x[i], 2) * end_val + pow(x[i], 3) * end_val;
   
   timer = micros();
   PWM_OUT();//PWM output
 }

}
void change_freq_error() {//Frequency variation is obtained from the standard deviation table
 dev = map(analogRead(devPot), 0, 1023, 0, 500);
 freq_rnd = random(500 - dev, 500 + dev);
 for (int k = 0; k < 32; k++) {
   if (freq_rnd >= chance[k] && freq_rnd < chance[k + 1]) {
     freq_dev = freq_err[k];
   }
 }
}

void PWM_OUT() {//PWM output
 analogWrite(cvOutput, bz_val * level / 255);
}
