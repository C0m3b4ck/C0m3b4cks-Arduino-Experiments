//original from www.elegoo.com
//remade by C0m3b4ck under APL 2.0

#include <Servo.h>
Servo myservo;

void setup(){
  Serial.begin(9600); //for debug prints
  randomSeed(analogRead(0)); //for randomization
  myservo.attach(9); //pin 9 attachment, change to your pin if needed
} 
void loop(){
  myservo.write(random(180));
  delay(random(1000));

}
