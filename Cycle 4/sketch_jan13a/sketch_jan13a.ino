//pin assignments
int pin7 = 7;
int pin8 = 8;


void setup() {
    // put your setup code here, to run once:
    // setup pinmode
    pinMode(pin7, OUTPUT);
    pinMode(pin8, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(pin7, HIGH);
    delay(1000);
    digitalWrite(pin7, LOW);
    delay(1000);
}
