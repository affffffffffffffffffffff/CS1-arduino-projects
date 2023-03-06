/* Video Link:
 * https://youtu.be/JYV-gtgj9wE
 */
#include <Wire.h>
#include "DS3231.h"

DS3231 clock;
RTCDateTime dt;

void setup() {
  Serial.begin(9600);

  Serial.println("Initialize RTC module");
  // Initialize DS3231
  clock.begin();
  // override to adjust run to run variances
  int overrideSeconds = -4;
  clock.setDateTime(clock.getDateTime().unixtime - overrideSeconds);
}

void loop() {
  dt = clock.getDateTime(); 

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);
}
