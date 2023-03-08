/* Video Link:
 * https://youtu.be/8gObFF2h51k
 */

#include "LiquidCrystal.h"
#include <Wire.h>
#include "DS3231.h"

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DS3231 clock;
RTCDateTime dt;

void setup() {
  clock.begin();
  int overrideSeconds = 0;
  clock.setDateTime(clock.getDateTime().unixtime - overrideSeconds);
  lcd.begin(16, 2);
}

void loop() {
  dt = clock.getDateTime();
  lcd.setCursor(0,0);
  lcd.print("*");
  if (abs(dt.hour - 12) < 10) {
    lcd.print("0");
    lcd.print(abs(dt.hour - 12));
  }
  else lcd.print(abs(dt.hour - 12));
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
  lcd.print("    ");
  lcd.print(dt.hour > 11 ? "PM" : "AM");
  lcd.print("*");
  lcd.setCursor(0,1);
  lcd.print("*");
  if (dt.year < 1000) {
    lcd.print("0");
  }
  if (dt.year < 100) {
    lcd.print("0");
  }
  if (dt.year < 10) {
    lcd.print("0");
  }
  lcd.print(dt.year);
  lcd.print("-");
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
  lcd.print("  ");
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
  lcd.setCursor(15,1);
  lcd.print("*");
}
