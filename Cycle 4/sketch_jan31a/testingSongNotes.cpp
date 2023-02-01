/* CONVERSION CODE

6 / 8 && 9 / 8 time signature
bpm 175 - 180

eighth note = delay(333);

music used: https://th.bing.com/th/id/OIP.WAFq8KYjc9Vf0G57E6zVJQHaK1?pid=ImgDet&rs=1

*/

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
  note5, note5, 

  note6, note7, note6, note5, note4, note3, 
  note2, note_6, 
  note_7, note_6, note_5, note5, note1, note2, 
  note3, note3, 

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note2_, note1_, 
  note6, note6, 

  note1_, note7, note6, note5, 
  note6, note5, note4, note3, 
  note_7, note_6, note_5, note2, 
  note1, note1, 

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 

  note7, note5, note3, note6, note6, 
  note5, note4, note3, note2, 
  note_7, note_6, note_5, note3, 
  note4, note2, note1, 
  note1, note1, note0, 

  // repeat

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note6, note3, 
  note5, note5, 

  note6, note7, note6, note5, note4, note3, 
  note2, note_6, 
  note_7, note_6, note_5, note5, note1, note2, 
  note3, note3, 

  note5, note6, note5, note4, note3, note2, 
  note1, note_5, 
  note1, note3, note1_, note7, note2_, note1_, 
  note6, note6, 

  note1_, note7, note6, note5, 
  note6, note5, note4, note3, 
  note_7, note_6, note_5, note2, 
  note1, note1, 

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 

  note7, note5, note3, note6, note6, 
  note5, note4, note3, note2, 
  note_7, note_6, note_5, note3, 
  note4, note2, note1, 
  note1, note1, note0, 

  // ending

  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note6, note3, note5, 
  note1_, note2_, note3_, note2_, note1_, note6, 
  note7, note5, note3, note6, 

  note5, note4, note3, note2, 
  note7, note6, note5, note3, 
  note3, note2_, note1_, 
  note1_, note1_
};

// length of note relative to eighth note
double length[] {
  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1, 1, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  3, 3, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  1.5, 0.5, 0.5, 3, 3, 
  1, 1, 1, 1, 1, 1, 

  1, 1.5, 0.5, 3, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  3, 2, 1, 

  // repeat

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1, 1, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  3, 3, 
  1, 1, 1, 1, 1.5, 0.5, 
  3, 3, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 3, 

  1, 1, 1, 1, 1, 1, 
  1.5, 0.5, 0.5, 3, 3, 
  1, 1, 1, 1, 1, 1, 

  1, 1.5, 0.5, 3, 3, 
  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  3, 2, 1, 

  // ending

  1, 1, 1, 1, 1, 1, 
  1, 1.5, 0.5, 3, 
  1, 1, 1, 1, 1, 1, 
  1, 1.5, 0.5, 3, 

  1, 1, 1, 3, 
  1, 1, 1, 3, 
  3, 2, 1, 
  3, 3
};

// plays note for length
delay((int)(333 * length[i]));

// MAKE SURE TO USE RIGHT DATA TYPE
// sizeof() returns in BYTES, NOT INT

for (int i = 0; i < (sizeof(notes)/sizeof(int)); i++) {}
