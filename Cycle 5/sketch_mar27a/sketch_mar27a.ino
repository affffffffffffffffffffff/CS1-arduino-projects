/* Video Link
 * https://youtu.be/oQY3sx6VllM
 */

// lib
#include<Wire.h>
#include "Stepper.h"

// consts
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; // gyro/accel raw values
const int stepsPerRevolution = 2038;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
const int stepAmount = 20; // amount motor moves before checking angle again
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// TUNE CONSTANTS HERE
const int UPPER_90 = 138;
const int UPPER_60 = 105;
const int LOWER_60 = 100;
const int UPPER_30 = 72;
const int LOWER_30 = 68;
const int LOWER_0  = 52;

// Arduino pin numbers
#define X_PIN 0 // analog pin connected to X output
#define Y_PIN 1 // analog pin connected to Y output

// containers for data
struct joystick {
  // raw joystick data
  int x_raw; 
  int y_raw;
  // processed input
  int x;
  int y;
}pos;
struct motor {
  int16_t currentPos; // gyro+accel movement control
  int deg;            // internal validation to stop out of bounds
  int lastDeg;        // internal validation to stop out of bounds
  bool clockwise;     // for indicating which way to move
}stepper;


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  myStepper.setSpeed(rolePerMinute); 
  Serial.begin(9600); // debug angles
}

void loop() {
  // read values
  pos.x_raw = analogRead(X_PIN);
  pos.y_raw = 1023 - analogRead(Y_PIN);
  // process values
  pos.x = (int)(pos.x_raw / 341.3);
  pos.y = (int)(pos.y_raw / 341.3);
  // do action based on joystick value
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
  // set clockwise and if move valid
  switch(a) {
    case -1: // down
      stepper.deg = stepper.lastDeg - 30;
      stepper.clockwise = true;
      break;
    case 0: // no mnove
      stepper.deg = stepper.lastDeg;
      return;
    case 1: // up
      stepper.deg = stepper.lastDeg + 30;
      stepper.clockwise = false;
      break;
    default:
      break;
  }
  // moving
  if (stepper.deg <= 90 && stepper.deg >= 0) { // for valid moves
    // switch to move to target
    /* Follows the following format
     * case ANGLE:
     *   while (CURRENT ANGLE NOT WITHIN ANGLE BOUNDS) {
     *     myStepper.step(CLOCKWISE OR COUNTERCLOCKWISE STEP AMOUNT);
     *     UPDATE_ANGLE(); 
     *     PAUSE;
     *   }
     *   break;
     */
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
  else { // for invalid moves
    stepper.deg = stepper.lastDeg; // undo invalid move
    Serial.println("out of range!");
  }

}

void updateDeg() {
  int accelAvg = 0;
  // measure and average 200 angle values
  for (int i = 0; i < 200; i++) {
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x3B); 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr,14,true); 
    AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
    AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
    int xAng = map(AcX,265,402,-90,90); 
    int yAng = map(AcY,265,402,-90,90); 
    accelAvg += RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  }
  stepper.currentPos = accelAvg / 200; // update angle value
  Serial.println(stepper.currentPos); // print debug
}
