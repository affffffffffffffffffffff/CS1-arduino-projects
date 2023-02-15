/* 
 *  Video Link: 
 *  https://youtu.be/DBgVB6xmNxQ
 */

// Arduino pin numbers
#define X_PIN 0 // analog pin connected to X output
#define Y_PIN 1 // analog pin connected to Y output
#define LL_PIN 3
#define BB_PIN 4
#define B_PIN 5
#define L_PIN 6
#define TT_PIN 7
#define T_PIN 8
#define M_PIN 9
#define R_PIN 10
#define RR_PIN 11
struct joystick {
  int x_raw;
  int y_raw;
  int x;
  int y;
}pos;

void setup() {
  for (int i = 3; i < 12; i++) { // output for all LEDs
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 3; i < 12; i++) { // reset all LEDs
    digitalWrite(i, 0);
  }
  pos.x_raw = analogRead(X_PIN);
  pos.y_raw = 1023 - analogRead(Y_PIN);
  pos.x = (int)(pos.x_raw / 204.8);
  pos.y = (int)(pos.y_raw / 204.8);
  if (abs(pos.x_raw - 512) >= abs(pos.y_raw - 512)) {
    switch(pos.x) {
      case 0:
        digitalWrite(LL_PIN, HIGH);
        break;
      case 1:
        digitalWrite(L_PIN, HIGH);
        break;
      case 2:
        digitalWrite(M_PIN, HIGH);
        break;
      case 3:
        digitalWrite(R_PIN, HIGH);
        break;
      case 4:
        digitalWrite(RR_PIN, HIGH);
        break;  
      default:
        break;
    }
  }
  else if (abs(pos.x_raw - 512) < abs(pos.y_raw - 512)) {
    switch(pos.y) {
      case 0:
        digitalWrite(BB_PIN, HIGH);
        break;
      case 1:
        digitalWrite(B_PIN, HIGH);
        break;
      case 2:
        digitalWrite(M_PIN, HIGH);
        break;
      case 3:
        digitalWrite(T_PIN, HIGH);
        break;
      case 4:
        digitalWrite(TT_PIN, HIGH);
        break;  
      default:
        break;
    }
  }
}
