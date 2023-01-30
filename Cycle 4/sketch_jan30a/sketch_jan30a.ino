/* 
 * Video Link:  
 * https://youtu.be/zb0CjdWZNQE
 */

#define LED_PIN 9
#define SPEAKER_PIN 8
#define ON_BUTTON 7
#define OFF_BUTTON 6


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(ON_BUTTON, INPUT_PULLUP);
  pinMode(OFF_BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ON_BUTTON) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(SPEAKER_PIN, LOW);
  }
  if(digitalRead(OFF_BUTTON) == LOW) {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(SPEAKER_PIN, HIGH);
  }
}
