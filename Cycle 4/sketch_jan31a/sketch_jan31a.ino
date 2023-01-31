/* 
 *  Video Link: https://youtu.be/WKFMjn0kM84
 */

#include "pitches.h"

int sequence[] = {
  NOTE_A4, NOTE_A4, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_A4, 
  NOTE_A4, NOTE_A4, NOTE_F3, NOTE_E3, NOTE_F3, NOTE_B4
};
int noteLength[] = {
  625, 625/2, 625/2, 625, 625/2, 625, 
  625, 625/2, 625/2, 625, 625/2, 625
};
int pauseLength[] {
  500, 500, 500, 500, 500, 500,
  500, 500, 500, 500, 500, 500
};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(sequence); i++) {
    tone(8, sequence[i], noteLength[i]);
    delay(pauseLength[i]);
  }
  delay(2000);
}
