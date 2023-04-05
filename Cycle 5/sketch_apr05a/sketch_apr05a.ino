// pin def
#define L1 22
#define L2 23
#define L3 24
#define L4 25
#define L5 26
#define L6 27
#define R_PIN 28
#define G_PIN 29

// libraries
#include "Keypad.h"
#include "Key.h"
#include <Servo.h>

// init
Servo myservo;
bool entry = true;
char password[6] = {'1', '2', '3', 'A', 'B', 'C'};
char customKey;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // put your setup code here, to run once:
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  myservo.attach(10);
  myservo.write(180);
}

void loop() {
  // reset passwd check and servo
  entry = true;
  myservo.write(180);
  // reset lights & make RGB red
  for (int i = 0; i < 6; i++) {
    digitalWrite(22+i, LOW);
  }
  digitalWrite(R_PIN, 1);
  digitalWrite(G_PIN, 0);
  // main function
  for (int i = 0; i < 6; i++) {
      do {customKey = customKeypad.getKey();} // poll membrane for action
      while (!customKey);
      if (customKey != password[i]) { // deny entry if any key is wrong
        entry = false;
      }
      digitalWrite(22+i, HIGH); // light up LED to show numbers entered
  }
  if (entry) {
    // set RGB to green
    digitalWrite(R_PIN, 0);
    digitalWrite(G_PIN, 1);
    // move servo
    myservo.write(25);
    // flash LED & start beep
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 6; j++) {
        digitalWrite(22+j, LOW);
      }
      tone(11, 1000);
      delay(100);
      for (int j = 0; j < 6; j++) {
        digitalWrite(22+j, HIGH);
      }
      delay(100);
      noTone(11);
      delay(75);
    }
    // continue beeping
    for (int i = 0; i < 5; i++) {
      tone(11, 1000);
      delay(200);
      noTone(11);
      delay(75);
    }
    // pause
    delay(2000);
  }
  else {
    // flash LED
    for (int i = 0; i < 6; i++) {
      digitalWrite(22+i, LOW);
    }
    delay(125);
    for (int i = 0; i < 6; i++) {
      digitalWrite(22+i, HIGH);
    }
    delay(125);
  }
  
}
