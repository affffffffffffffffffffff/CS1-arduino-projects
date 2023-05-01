/* Video Link:
 * https://youtu.be/***********
 */

#include "LedControl.h"
#define SENSORANALOG A0  // analog input sound sensor
#define SENSORDIGITAL 2  // digital input from sound sensor
#define CALIBRATION 500  // Calibrate Volume Floor to find decibals
#define DISPLAYCAL 1     // Calibrate display range of decibal values
byte displayLevel[9] = {B00000000,B00000001,B00000011,B00000111,B00001111,B00011111,B00111111,B01111111,B11111111}; 
LedControl lc = LedControl(12,10,11,1); // initialize dot matrix display
int decibals;
int processed;

void setup() {
  Serial.begin(9600);
  pinMode(SENSORDIGITAL,INPUT); // set sound pin as digital input
  pinMode(LED_BUILTIN,OUTPUT);  // set inbuilt pin LED as output
  lc.shutdown(0, false);        // led screen wakeup
  lc.setIntensity(0, 8);        // led screen medium brightness
  lc.clearDisplay(0);           // clear led screen
}

void loop() {
  // get microphone input volume & convert signal to decibals
  decibals = 10*log10(analogRead(SENSORANALOG)/CALIBRATION);
  Serial.println(decibals); // debug
  // prep values for display
  processed = decibals/10 - DISPLAYCAL;
  if (processed < 0) processed = 0; // low pass filter
  if (processed > 8) processed = 8; // high pass filter
  // display decibal on screen
  for (int i = 0; i < 8; i++) {
	lc.setRow(0, i, displayLevel[processed]);
  }
  delay(50);  
}