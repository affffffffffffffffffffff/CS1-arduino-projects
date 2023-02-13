/* 
 *  Video Link: 
 *  https://youtu.be/eOhj6oTI3SU
 */

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin) == 0 ? 1 : 0);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(1023 - analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
}


// down   Y_pin     0
// up     Y_pin     1023
// left   X_pin     0
// right  X_PIN     1023
// button pressed   1
// button !presseed 0
