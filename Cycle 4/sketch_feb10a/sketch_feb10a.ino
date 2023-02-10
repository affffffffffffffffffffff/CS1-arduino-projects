/* 
 *  Video Link
 *  https://youtu.be/tgio76aHGvs
 *  
 *  Using scale 5cm
 *  
 */

#include <Servo.h>
#include "SR04.h"
Servo myservo;
const int trigPin = 2;
const int echoPin = 3;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;
const int led5 = 9;
SR04 sr04 = SR04(echoPin, trigPin);
long a;
int ctrl;

void setup(){
  // init
  Serial.begin(9600);
  delay(1000);
  myservo.attach(8);
  myservo.write(90);// move servos to center position -> 90°
} 
void loop(){
  // set distance & output serial
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  // reset previous LED
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
  digitalWrite(led5, 0);
  // led control
  if (a >= 25) {
    digitalWrite(led5, 1);
    myservo.write(30);
  }
  else if (a >= 20) {
    digitalWrite(led4, 1);
    myservo.write(60);
  }
  else if (a >= 15) {
    digitalWrite(led3, 1);
    myservo.write(90);
  }
  else if (a >= 10) {
    digitalWrite(led2, 1);
    myservo.write(120);
  }
  else if (a >= 5) {
    digitalWrite(led1, 1);
    myservo.write(150);
  }
  else {
    myservo.write(180);
  }
  // wait
  delay(100);
}
