/* 
 * Video Link:  
 * https://youtu.be/0mYzH-QZBWg
 */

#define LED_PIN 5
#define ON_BUTTON 9
#define OFF_BUTTON 8


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(ON_BUTTON, INPUT_PULLUP);
  pinMode(OFF_BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ON_BUTTON) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  }
  if(digitalRead(OFF_BUTTON) == LOW) {
    digitalWrite(LED_PIN, LOW);
  }
}
