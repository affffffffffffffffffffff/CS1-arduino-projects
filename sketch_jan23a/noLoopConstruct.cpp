//pins
#define RED_PIN
#define GREEN_PIN
#define BLUE_PIN

// color flags
int currentR, currentG, currentB = 0;
int currentColor = 0;

// SET COLORS HERE
int numColors = 5;
int RValue[numColors] = {};
int GValue[numColors] = {};
int BValue[numColors] = {};

// flags for control flow
bool showedColor = false;
bool increasing = true;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    // fade in
    if((currentR < RValue[currentColor] || currentG < GValue[currentColor] || currentB < BValue[currentColor]) && increasing) {
        if(showedColor) {
            showedColor = false;
        }
        if(currentR < COLOR_R) {
            currentR++;
            analogWrite(RED_PIN, currentR);
        }
        if(currentG < COLOR_G) {
            currentG++;
            analogWrite(GREEN_PIN, currentG);
        }
        if(currentB < COLOR_B) {
            currentB++;
            analogWrite(BLUE_PIN, currentB);
        }
        // break loop
        if(currentR == RValue[currentColor] && currentG == GValue[currentColor] && currentB == BValue[currentColor]) {
            increasing = false;
        }
        delay(1);
    }
    // decrease
    else if((!increasing) && (currentR != 0 && currentG != 0 && currentB != 0))  {
        // pause for color if not shown
        if(!showedColor) {
            delay(2000);
            showedColor = true;
        }
        if(currentR > 0) {
            currentR--;
            analogWrite(RED_PIN, currentR);
        }
         if(currentG > 0) {
            currentG--;
            analogWrite(GREEN_PIN, currentG);
        }
        if(currentB > 0) {
            currentB--;
            analogWrite(BLUE_PIN, currentB);
        }
        delay(1);
    }
    else {
        increasing = true;
        if (currentColor < numColors) {
            currentColor++;
        else {
            currentColor = 0;
        }
    }
}
