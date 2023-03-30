/* Video Links
 * Working fully but forgot to draw arc:
 *  > https://youtu.be/2XwkIEiyDjY
 * Working with arc but accelerometer slightly miscalibrated: 
 *  > https://youtu.be/_o1uoFSN7Co
 */

// lib
#include<Wire.h>
#include "Stepper.h"

// consts
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
const int stepsPerRevolution = 2038;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
const int stepAmount = 30; // amount motor moves before checking angle again
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// TUNE CONSTANTS HERE
const int correction = 0; 
const int UPPER_90 = 90+correction;
const int UPPER_60 = 65+correction;
const int LOWER_60 = 55+correction;
const int UPPER_30 = 35+correction;
const int LOWER_30 = 25+correction;
const int LOWER_0  = 0+correction;

// Arduino pin numbers
#define X_PIN 0 // analog pin connected to X output
#define Y_PIN 1 // analog pin connected to Y output

// containers for data
struct joystick {
  int x_raw;
  int y_raw;
  int x;
  int y;
}pos;
struct motor {
  int16_t avgPos;    // gyro movement control
  int16_t currentPos; // gyro movement control
  int deg;            // internal validation
  int lastDeg;        // internal validation
  bool clockwise;     // for indicating which way to move
}stepper;


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  myStepper.setSpeed(rolePerMinute); // pid this pls
  Serial.begin(9600); 
}

void loop() {
  pos.x_raw = analogRead(X_PIN);
  pos.y_raw = 1023 - analogRead(Y_PIN);
  pos.x = (int)(pos.x_raw / 341.3);
  pos.y = (int)(pos.y_raw / 341.3);
  if (abs(pos.x_raw - 512) >= abs(pos.y_raw - 512)) {
    Serial.print("triggerred x "); // debug
    Serial.println(pos.x - 1);
    change(pos.x - 1);
  }
  else if (abs(pos.x_raw - 512) < abs(pos.y_raw - 512)) {
    Serial.print("triggerred y "); // debug
    Serial.println(pos.y - 1);
    change(pos.y - 1);
  }
  updateDeg(); // debug
}

void change(int a) {
  switch(a) {
    case -1:
      stepper.deg = stepper.lastDeg - 30;
      stepper.clockwise = true;
      break;
    case 0:
      stepper.deg = stepper.lastDeg;
      return;
    case 1:
      stepper.deg = stepper.lastDeg + 30;
      stepper.clockwise = false;
      break;
    case 2: //reset
      stepper.deg = 0;
      break;
    default:
      break;
  }
  if (stepper.deg <= 90 && stepper.deg >= 0) {
    // moving
    switch(stepper.deg) {
      case 90:
        while (stepper.currentPos < UPPER_90) {
          myStepper.step(stepAmount);
          updateDeg();
          delay(1);
        }
        break;
      case 60:
        while (stepper.currentPos > UPPER_60 || stepper.currentPos < LOWER_60) {
          myStepper.step(stepper.clockwise ? -stepAmount : stepAmount);
          updateDeg();
          delay(1);
        }
        break;
      case 30:
        while (stepper.currentPos > UPPER_30 || stepper.currentPos < LOWER_30) {
          myStepper.step(stepper.clockwise ? -stepAmount : stepAmount);
          updateDeg();
          delay(1);
        }
        break;
      case 0:
        while (stepper.currentPos > LOWER_0) {
          myStepper.step(-stepAmount);
          updateDeg();
          delay(1);
        }
        break;
      default:
        updateDeg();
        break;
    }
    stepper.lastDeg = stepper.deg; // prep for next move
  }
  else {
    stepper.deg = stepper.lastDeg; // undo invalid move
    Serial.println("out of range!");
  }

}

void updateDeg() {
  stepper.avgPos = 0;
  for (int i = 0; i < 150; i++) {
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x3B); 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr,14,true); 
    AcX=Wire.read()<<8|Wire.read(); 
    AcY=Wire.read()<<8|Wire.read();
    int xAng = map(AcX,265,402,-90,90); 
    int yAng = map(AcY,265,402,-90,90); 
    stepper.avgPos += RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  }
  stepper.currentPos = stepper.avgPos / 150;
  Serial.println(stepper.currentPos); // debug
}
