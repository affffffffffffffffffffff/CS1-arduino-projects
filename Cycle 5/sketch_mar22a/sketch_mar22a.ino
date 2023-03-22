/* Video Link:
 * https://youtu.be/jf56VGvDk4I
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
  for (int i = 0; i < 75; i++) {
    analogWrite(DIRA, i);
    delay(150);
  }    
  analogWrite(DIRA, 150);
  delay(50);
  analogWrite(DIRA, 75);
  delay(1000); //inertia
  for (int i = 125; i < 256; i++) {
    analogWrite(DIRA, i);
    delay(20);
  }
  Serial.println("max clockwise speed reached");
  delay(2000); 
  Serial.println("spin down clockwise"); //spinup cw
  for (int i = 255; i > 70; i--) {
    analogWrite(DIRA, i);
    delay(20);
  }    
  analogWrite(DIRA, 70);
  delay(1000);
  for (int i = 70; i > 0; i--) {
    analogWrite(DIRA, i);
    delay(100);
  }  
  digitalWrite(DIRA, LOW);
  Serial.println("spin up counter-clockwise"); //spinup ccw
  for (int i = 0; i < 75; i++) {
    analogWrite(DIRB, i);
    delay(150);
  }    
  analogWrite(DIRB, 150);
  delay(50);
  analogWrite(DIRB, 75);
  delay(1000); //inertia
  for (int i = 125; i < 256; i++) {
    analogWrite(DIRB, i);
    delay(20);
  }
  Serial.println("max counter-clockwise speed reached");
  delay(2000);
  Serial.println("spin doiwn counter-clockwise"); //spindown ccw
  for (int i = 255; i > 70; i--) {
    analogWrite(DIRB, i);
    delay(20);
  }    
  analogWrite(DIRB, 70);
  delay(1000);
  for (int i = 70; i > 0; i--) {
    analogWrite(DIRB, i);
    delay(100);
  }    
  digitalWrite(DIRB, LOW);
}
   
