#include <Servo.h>
#include <LiquidCrystal.h>


#define LedPinRED 7
#define BuzzerPin 8
#define LedPinGreen 6

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo servo;
int angle = 10;

void setup() {
  Serial.begin(9600);
  pinMode(LedPinRED, OUTPUT);
  pinMode(LedPinGreen, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  servo.attach(9);
  servo.write(angle);
  lcd.begin(16, 2);
  lcd.print("Nibras Noob");
}

void loop() {



  if (Serial.available()) {
    char Data = Serial.read();



    switch (Data) {
      case 'O':

        digitalWrite(LedPinGreen, HIGH);
        digitalWrite(BuzzerPin, HIGH);
        delay(200);
        digitalWrite(LedPinGreen, HIGH);
        digitalWrite(BuzzerPin, HIGH);
        delay(200);
        digitalWrite(LedPinGreen, LOW);
        digitalWrite(BuzzerPin, LOW);
        for (angle = 10; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }


        break;
      case 'F':

        digitalWrite(LedPinRED, HIGH);
        digitalWrite(BuzzerPin, HIGH);
        delay(200);
        digitalWrite(LedPinRED, LOW);
        digitalWrite(BuzzerPin, LOW);
        delay(200);
        digitalWrite(LedPinRED, HIGH);
        digitalWrite(BuzzerPin, HIGH);
        delay(200);
        digitalWrite(LedPinRED, LOW);
        digitalWrite(BuzzerPin, LOW);
        delay(200);
        for (angle = 180; angle > 10; angle--) {
          servo.write(angle);
          delay(15);
        }
        break;
    }
  }
}
