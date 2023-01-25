//pin assignments
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);

    // countdown blinks
  for(int i = 0; i < 3; i++) {
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 1);
    digitalWrite(pin7, 1);
    delay(2000);
    digitalWrite(pin4, 0);
    digitalWrite(pin5, 0);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 0);
    delay(750);
  }
}

void loop() {
  // main loop
  function11();
  delay(750);
  function15();
  delay(125);
  function13();
  delay(625);
  function5();
  delay(175);
  function7();
  delay(75);
  function6();
  delay(750);
  function14();
  delay(250);
  function15();
  delay(125);
  function11();
  delay(375);
  function9();
  delay(500);
  function8();
  delay(625);
  function0();
  delay(475);
  function4();
  delay(150);
  function6();
  delay(250);
  function14();
  delay(175);
  function15();
  delay(675);
  function11();
  delay(175);
  function10();
  delay(50);
  function8();
  delay(50);
  function0();
  delay(250);
}

void function0() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 0);
}

void function4() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 0);
}

void function5() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 1);
}

void function6() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 0);
}

void function7() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
}

void function8() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 0);
}

void function9() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 1);
}

void function10() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 0);
}

void function11() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
}

void function13() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 1);
}

void function14() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 0);
}

void function15() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
}
