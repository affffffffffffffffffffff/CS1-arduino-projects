/*
 * Video Link: 
 * 
 * Original Song: 我和我的祖国 (My People, My Country)
 *  
 */

// Actual code after declarations starts on line 263

#include "pitches.h"

// declare pins
#define BUZZER_PIN 2
int ledCounter = 2;

// code to translate library's staff notation to jianpu notation
const int note0 = 0;
const int note_5 = NOTE_G3;
const int note_6 = NOTE_A4;
const int note_7 = NOTE_B4;
const int note1 = NOTE_C4;
const int note2 = NOTE_D4;
const int note3 = NOTE_E4;
const int note4 = NOTE_F4;
const int note5 = NOTE_G4;
const int note6 = NOTE_A5;
const int note7 = NOTE_B5;
const int note1_ = NOTE_C5;
const int note2_ = NOTE_D5;
const int note3_ = NOTE_E5;

// sequence of notes to play
int notes[] {
  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note6, note3, 
  note5, 

  note6, note7, note6, note5, note4, note3, 
  note2, note_6, 
  note_7, note_6, note_5, note5, note1, note2, 
  note3, 

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note2_, note1_, 
  note6, 

  note1_, note7, note6, note5, 
  note6, note5, note4, note3, 
  note_7, note_6, note_5, note2, 
  note1, 

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 

  note7, note5, note3, note6, 
  note5, note4, note3, note2, 
  note_7, note_6, note_5, note3, 
  note4, note2, note1, 
  note1, note0, 

  // repeat

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note6, note3, 
  note5, 

  note6, note7, note6, note5, note4, note3, 
  note2, note_6, 
  note_7, note_6, note_5, note5, note1, note2, 
  note3, 

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note2_, note1_, 
  note6, 

  note1_, note7, note6, note5, 
  note6, note5, note4, note3, 
  note_7, note_6, note_5, note2, 
  note1, 

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 

  note7, note5, note3, note6, 
  note5, note4, note3, note2, 
  note_7, note_6, note_5, note3, 
  note4, note2, note1, 
  note1, note0, 

  // ending

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note5, note3, note6, 

  note5, note4, note3, note2, 
  note7, note6, note5, note3, 
  note3, note2_, note1_, 
  note1_
};

// length of note relative to eighth note
double length[] {
  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1, 1, 
  6, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  6, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  6, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  6, 

  1, 1, 1, 1, 1, 1, 
  1.5, 0.5, 0.5, 6, 
  1, 1, 1, 1, 1, 1, 

  1, 1.5, 0.5, 6, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  5, 1, 

  // repeat

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1, 1, 
  6, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  6, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  6, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  6, 

  1, 1, 1, 1, 1, 1, 
  1.5, 0.5, 0.5, 6, 
  1, 1, 1, 1, 1, 1, 

  1, 1.5, 0.5, 6, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  5, 1, 

  // ending

  1, 1, 1, 1, 1, 1, 
  1, 1.5, 0.5, 3, 
  1, 1, 1, 1, 1, 1, 
  1, 1.5, 0.5, 3, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  6
};

// use this to define breath change and rests where no pause = 0 and pause = 1
int pauses[] {
  0, 0, 0, 0, 0, 0, 
  0, 1, 
  0, 0, 0, 0, 0, 0,
  1, 

  0, 0, 0, 0, 0, 0,
  0, 1, 
  0, 0, 0, 0, 0, 0, 
  1, 

  0, 0, 0, 0, 0, 0, 
  0, 1, 
  0, 0, 0, 0, 0, 0, 
  1, 

  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 0, 
  1, 

  0, 0, 0, 0, 0, 0, 
  0, 0, 0, 1, 
  0, 0, 0, 0, 0, 0, 

  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 
  0, 1, 

  // repeat

  0, 0, 0, 0, 0, 0, 
  0, 1, 
  0, 0, 0, 0, 0, 0,
  1, 

  0, 0, 0, 0, 0, 0,
  0, 1, 
  0, 0, 0, 0, 0, 0, 
  1, 

  0, 0, 0, 0, 0, 0, 
  0, 1, 
  0, 0, 0, 0, 0, 0, 
  1, 

  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 0, 
  1, 

  0, 0, 0, 0, 0, 0, 
  0, 0, 0, 1, 
  0, 0, 0, 0, 0, 0, 

  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 
  0, 1, 
  
  // ending

  0, 0, 0, 0, 0, 0, 
  0, 0, 0, 1, 
  0, 0, 0, 0, 0, 0, 
  0, 0, 0, 1, 

  0, 0, 0, 1, 
  0, 0, 0, 1, 
  0, 0, 0, 
  1
};

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  for (int i = 0; i < (sizeof(notes)/sizeof(int)); i++) {
    LEDHandler(0);
    if (notes[i] != 0) {
      tone(BUZZER_PIN, notes[i]);
      LEDHandler(1);
    }
    delay((int)(333 * length[i]));
    noTone(BUZZER_PIN);
    delay(50 * pauses[i]);
  }
  delay(5000);
}

void LEDHandler(int action) {
  if (action == 1) {
    digitalWrite(ledCounter, HIGH);
  }
  else if (action == 0) {
    digitalWrite(ledCounter, LOW);
    if (ledCounter < 9) {
      ledCounter++;
    }
    else if (ledCounter == 9) {
      ledCounter = 3;
    }
  }
}
