#include "fonc.h"
#define LedPinRED 7
#define BuzzerPin 8
#define LedPinGreen 6

void setup_all(){

  SetupLED(LedPinRED);
  SetupLED(LedPinGreen);
  SetupLED(BuzzerPin);
}

void oncase(){
        LED_H(LedPinGreen);
        LED_H(BuzzerPin);
        delay(200);
        LED_L(LedPinGreen);
        LED_L(BuzzerPin);
        delay(200);
        LED_L(LedPinGreen);
        LED_L(BuzzerPin);

  
}

void offcase(){


        LED_H(LedPinRED);
        LED_H(BuzzerPin);
        delay(200);
        LED_L(LedPinRED);
        LED_L(BuzzerPin);
        delay(200);
        LED_H(LedPinRED);
        LED_H(BuzzerPin);
        delay(200);
        LED_L(LedPinRED);
        LED_L(BuzzerPin);
        delay(200);


}

void SetupLED(byte pin){
  pinMode(pin ,OUTPUT);
}
void LED_H(byte pin){
   digitalWrite(pin, HIGH);
}
void LED_L(byte pin){
   digitalWrite(pin, LOW);
}