/*
 * Video Link:
 * https://youtu.be/RO887gRb5-A/
 */

// pin def
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
  for (int i = 0; i < 3; i++) {
    function15();
    delay(1000);
    function0();
    delay(750);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  function5();
  delay(280);
  function12();
  delay(280);
  function14();
  delay(280);
  function15();
  delay(140);
  function11();
  delay(280);
  function3();
  delay(280);
  function1();
  delay(280);
  function0();
  delay(700);
  function4();
  delay(280);
  function12();
  delay(280);
  function14();
  delay(280);
  function11();
  delay(280);
  function3();
  delay(280);
  function1();
  delay(280);
  function0();
  delay(630);
  function4();
  delay(280);
  function12();
  delay(280);
  function14();
  delay(280);
  function15();
  delay(490);
  function11();
  delay(280);
  function3();
  delay(280);
}

void function0() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 0);
}

void function1() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 1);
}

void function3() {
  digitalWrite(pin4, 0);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
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

void function11() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 0);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
}

void function12() {
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 0);
  digitalWrite(pin7, 0);
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
