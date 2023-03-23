/* Video Link:
 * https://youtu.be/6N80SaPqaUg
 */

#define ENABLE 5
#define DIRA 3
#define DIRB 4
//int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ENABLE, HIGH);
  Serial.println("spin up clockwise"); //spinup cw
  for (int i = 0; i < 256; i++) {
    analogWrite(DIRA, i);
    delay(15);
  }    
  Serial.println("max clockwise speed reached");
  delay(2000); 
  Serial.println("spin down clockwise"); //spinup cw
  for (int i = 255; i >= 0; i--) {
    analogWrite(DIRA, i);
    delay(20);
  }
  delay(1000);
  Serial.println("spin up counter-clockwise"); //spinup ccw
  for (int i = 0; i < 256; i++) {
    analogWrite(DIRB, i);
    delay(15);
  }   
  Serial.println("max counter-clockwise speed reached");
  delay(2000);
  Serial.println("spin doiwn counter-clockwise"); //spindown ccw
  for (int i = 255; i >= 0; i--) {
    analogWrite(DIRB, i);
    delay(20);
  }
  delay(1000);
}
   
