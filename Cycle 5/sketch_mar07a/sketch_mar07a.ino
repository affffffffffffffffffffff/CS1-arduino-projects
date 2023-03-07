/* Video Link:
 *  https://youtu.be/v6cACoNskyE
 */

/*
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include "LiquidCrystal.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(6, 0);
  lcd.print("CVHS");
  delay(1000);
  lcd.setCursor(6, 0);
  lcd.print("    ");
  lcd.setCursor(5, 1);
  lcd.print("Rhinos");
  delay(1000);
  lcd.setCursor(5, 1);
  lcd.print("      ");
}
