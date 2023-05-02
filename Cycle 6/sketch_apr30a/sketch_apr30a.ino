/* Video Link:
 * https://youtu.be/sWdidN0pQCw
 */

// READ ME
// 1. Your potentiometer may vary. You will have to adjust your variables.
// 2. Your environment may vary. You will have to adjust your variables.
// 3. Adjust the MINVOLTAGE/MAXVOLTAGE constants to tune to your environment.
// 4. Projects with sensors are so variable and unreliable at times.

#include "LedControl.h" // lib
#define SENSORANALOG A0 // a_input pin from sound sensor
#define SENSORDIGITAL 2 // d_input pin from sound sensor
#define MINVOLTAGE 525  // Calibrate voltage for loud sound
#define MAXVOLTAGE 550  // Calibrate noise floor (quiet)
byte displayLevel[9] = {B00000000,B00000001,B00000011,B00000111,B00001111,B00011111,B00111111,B01111111,B11111111}; // define display modes
LedControl lc = LedControl(12,10,11,1); // initialize dot matrix display
// variable
long dataIn = 0;
int processed;
int processedOld;
bool hold;
bool highHold;

void setup() {
  Serial.begin(9600);           // for debug
  pinMode(SENSORDIGITAL,INPUT); // set sound pin as digital input
  lc.shutdown(0,false);         // led screen wakeup
  lc.setIntensity(0,8);         // led screen medium brightness
  lc.clearDisplay(0);           // clear led screen
}

void loop() {
  // get microphone input voltage
  dataIn = analogRead(SENSORANALOG);
  Serial.println(dataIn); // debug
  // prep values for display
  processed = map(dataIn, MINVOLTAGE, MAXVOLTAGE-5, 8, 1); // higher voltage means lower volume
  processed = constrain(processed,1,8); // map accepts & returns out of range values, so filtering
  Serial.println(processed); // debug
  // display level  on screen 
  if (hold && processedOld > processed) { // hold previous level if high
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, displayLevel[processedOld]);
    }
    delay(30);
    hold = false;
    if (processed == 8 && processedOld == 8) highHold = true;
  }
  else if (highHold && processedOld == 8) { // holding very high level (anti-flicker)
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, 8);
    }
    delay(1000);
    highHold = false;
  }
  else { // display
    for (int i = 0; i < 8; i++) {
	    lc.setRow(0, i, displayLevel[processed]);
    }
    hold = true;
  }
  processedOld = processed;
  dataIn = 0;
  processed = 0;
  delay(20);
}
