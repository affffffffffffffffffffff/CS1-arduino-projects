/*
 * Video Link:
 * https://youtu.be/wAMJh6sYvnI
 */

#include "LedControl.h"

/* The sequence of characters to play. The code is generalized
 * so any sequence made up of 6-pixel wide characters wide works.
 * The characters are 5px content, 1px padding.
 */
// Sentence: "You are what you eat!"
byte sequence[22][6] = { 
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //
  {B00000000,B00000000,B00000000,B00000000,B00000000,B11111101}, //!
  {B00000000,B00010001,B00010001,B01111110,B00010000,B00010000}, //t
  {B00000000,B00001111,B00010010,B00010001,B00010001,B00001110}, //a
  {B00000000,B00001000,B00010101,B00010101,B00010101,B00001110}, //e
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //
  {B00000000,B00011111,B00000010,B00000001,B00000001,B00011110}, //u
  {B00000000,B00001110,B00010001,B00010001,B00010001,B00001110}, //o
  {B00000000,B00111110,B00000101,B00000101,B00000101,B00111001}, //y
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //
  {B00000000,B00010001,B00010001,B01111110,B00010000,B00010000}, //t
  {B00000000,B00001111,B00010010,B00010001,B00010001,B00001110}, //a
  {B00000000,B00001111,B00010000,B00010000,B00010000,B11111111}, //h
  {B00000000,B00011110,B00000001,B00011110,B00000001,B00011110}, //w
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //
  {B00000000,B00001000,B00010101,B00010101,B00010101,B00001110}, //e
  {B00000000,B00001000,B00010000,B00010000,B00001000,B00011111}, //r
  {B00000000,B00001111,B00010010,B00010001,B00010001,B00001110}, //a
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //
  {B00000000,B00011111,B00000010,B00000001,B00000001,B00011110}, //u
  {B00000000,B00001110,B00010001,B00010001,B00010001,B00001110}, //o
  {B00000000,B11100000,B00010000,B00001111,B00010000,B11100000}};//Y
LedControl lc = LedControl(12,10,11,1);

void setup() {
  lc.shutdown(0, false); // wakeup
  lc.setIntensity(0, 8); // medium brightness
  lc.clearDisplay(0); // clear display
}

/* There's this weird thing that happens during frames
 * 1 - 8, where random garbled data is sent to the screen.
 * The additional else statements help to mediate this issue.
 * The code should still be generalized.
 */
void writeWordOnMatrix() { 
  for (int i = sizeof(sequence); i > 0; i--) {
    int j = i / 6;
    int k = i % 6;
    if (i < sizeof(sequence) - 7) { // most of the sequence
      lc.setRow(0, 0, sequence[j][k]);
      lc.setRow(0, 1, sequence[j][k + 1]);
      lc.setRow(0, 2, sequence[j][k + 2]);
      lc.setRow(0, 3, sequence[j][k + 3]);
      lc.setRow(0, 4, sequence[j][k + 4]);
      lc.setRow(0, 5, sequence[j][k + 5]);
      lc.setRow(0, 6, sequence[j][k + 6]);
      lc.setRow(0, 7, sequence[j][k + 7]);
    }
    else if (i < sizeof(sequence) - 6) { // transition to rest of the sequence
      lc.setRow(0, 0, sequence[j][k - 4]);
      lc.setRow(0, 1, sequence[j][k - 5]);
      lc.setRow(0, 2, sequence[j + 1][k]);
      lc.setRow(0, 3, sequence[j + 1][k - 1]);
      lc.setRow(0, 4, sequence[j + 1][k - 2]);
      lc.setRow(0, 5, sequence[j + 1][k - 3]);
      lc.setRow(0, 6, sequence[j + 1][k - 4]);
      lc.setRow(0, 7, sequence[j + 1][k - 5]);
    }
    else if (i < sizeof(sequence) - 5) { // transition to 2nd letter
      lc.setRow(0, 0, sequence[j - 1][k]);
      lc.setRow(0, 1, sequence[j][k + 5]);
      lc.setRow(0, 2, sequence[j][k + 4]);
      lc.setRow(0, 3, sequence[j][k + 3]);
      lc.setRow(0, 4, sequence[j][k + 2]);
      lc.setRow(0, 5, sequence[j][k + 1]);
      lc.setRow(0, 6, sequence[j][k]);
    }
    else { // first letter
      if (j == sizeof(sequence) / 6) j -= 1;
      if (k == 0) k = 6;
      if (i < 128) lc.setRow(0, 5, sequence[j][1 - k]);
      if (i < 129) lc.setRow(0, 4, sequence[j][2 - k]);
      if (i < 130) lc.setRow(0, 3, sequence[j][3 - k]);
      if (i < 131) lc.setRow(0, 2, sequence[j][4 - k]);
      if (i < 132) lc.setRow(0, 1, sequence[j][5 - k]);
      lc.setRow(0, 0, sequence[j][6 - k]);
    }
    delay(200);
  }
}

void loop() { 
  writeWordOnMatrix();
}
