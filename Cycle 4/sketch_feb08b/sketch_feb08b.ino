/*
 * Video Link
 * https://youtu.be/oodu6l1qRuU
 */

#include "SR04.h"
const int trigPin = 12;
const int echoPin = 11;
SR04 sr04 = SR04(echoPin, trigPin);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a = sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}
