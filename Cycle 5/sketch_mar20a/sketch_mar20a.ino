/* Video Link:
 * https://youtu.be/hvIAUFYS2Hc
 */

#include "LiquidCrystal.h"
#include <Wire.h>
#include "DS3231.h"
#include "dht_nonblocking.h"
#define DHT_SENSOR_TYPE DHT_TYPE_11

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DS3231 clock;
RTCDateTime dt;
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  clock.begin();
  int overrideSeconds =  -5;
  clock.setDateTime(__DATE__, __TIME__);
  clock.setDateTime(clock.getDateTime().unixtime - overrideSeconds);
  lcd.begin(16, 2);
}

/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment(float *temperature, float *humidity) {
  static unsigned long measurement_timestamp = millis();
  /* Measure once every two seconds. */
  if(millis() - measurement_timestamp > 1000ul) {
    if(dht_sensor.measure(temperature, humidity) == true) {
      measurement_timestamp = millis();
      return(true);
    }
  }
  return(false);
}

void loop() {
  dt = clock.getDateTime();
  float temperature;
  float humidity;
  lcd.setCursor(0,0);
  if (dt.month < 10) {
    lcd.print("0");
    lcd.print(dt.month);
  }
  else lcd.print(dt.month);
  if (dt.day < 10) {
    lcd.print("0");
    lcd.print(dt.day);
  }
  else lcd.print(dt.day);
  lcd.print(" ");
  if (dt.hour < 10 || (dt.hour > 12 && dt.hour - 12 < 10)) {
    lcd.print("0");
    lcd.print(abs(dt.hour - 12));
  }
  else lcd.print(dt.hour > 12 ? abs(dt.hour - 12) : dt.hour);
  lcd.print(":");
  if (dt.minute < 10) {
    lcd.print("0");
    lcd.print(dt.minute);
  }
  else lcd.print(dt.minute);
  lcd.print(":");
  if (dt.second < 10) {
    lcd.print("0");
    lcd.print(dt.second);
  }
  else lcd.print(dt.second);
  lcd.print(" ");
  lcd.print(dt.hour > 11 ? "PM" : "AM");
  lcd.setCursor(0,1);
  switch (dt.dayOfWeek) {
    case 0:
      lcd.print("Sun");
      break;
    case 1:
      lcd.print("Mon");
      break;
    case 2:
      lcd.print("Tue");
      break;
    case 3:
      lcd.print("Wed");
      break;  
    case 4:
      lcd.print("Thu");
      break;
    case 5:
      lcd.print("Fri");
      break;
    case 6:
      lcd.print("Sat");
      break;
  }
  lcd.print(" ");
  if(measure_environment(&temperature,&humidity) == true) {
    lcd.print(humidity);
    lcd.setCursor(8,1);
    lcd.print("% ");
    lcd.print(temperature / 5 * 9 + 32);
    lcd.setCursor(14,1);
    lcd.print(" F");
  }
}
