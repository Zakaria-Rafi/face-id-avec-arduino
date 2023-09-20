#define LedPinRED 13
#define BuzzerPin 12
#define LedPinGreen 11
void setup() {
  Serial.begin(9600);
  pinMode(LedPinRED,OUTPUT);
  pinMode(LedPinGreen,OUTPUT);
  pinMode(BuzzerPin , OUTPUT);
}

void loop() {

  if(Serial.available()){
    char Data = Serial.read();



    switch(Data){
      case 'O' :
      
      digitalWrite(LedPinGreen , HIGH);
      digitalWrite(BuzzerPin , HIGH);
      delay(200);
      digitalWrite(LedPinGreen , HIGH);
      digitalWrite(BuzzerPin , HIGH);
      delay(200);
      digitalWrite(LedPinGreen , LOW);
      digitalWrite(BuzzerPin , LOW);



      break;
      case 'F':
      
      digitalWrite(LedPinRED, HIGH);
      digitalWrite(BuzzerPin , HIGH);
      delay(200);
      digitalWrite(LedPinRED, LOW);
      digitalWrite(BuzzerPin , LOW);     
      delay(200);
      digitalWrite(LedPinRED, HIGH);
      digitalWrite(BuzzerPin , HIGH);
      delay(200);
      digitalWrite(LedPinRED, LOW);
      digitalWrite(BuzzerPin , LOW);     
      delay(200);
      break;
      


    }



  }

}
