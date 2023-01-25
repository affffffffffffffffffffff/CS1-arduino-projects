//pin assignments
int pin7 = 7;
int pin6 = 6;
int pin5 = 5;
int pin4 = 4;
int pin3 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin6, LOW);
  digitalWrite(pin3, HIGH);
  delay(1000);
  digitalWrite(pin7, LOW);
  digitalWrite(pin4, HIGH);
  delay(1000);
  digitalWrite(pin3, LOW);
  digitalWrite(pin5, HIGH);
  delay(1000);
  digitalWrite(pin4, LOW);
  digitalWrite(pin6, HIGH);
  delay(1000);
  digitalWrite(pin5, LOW);
  digitalWrite(pin7, HIGH);
  delay(1000);

}
