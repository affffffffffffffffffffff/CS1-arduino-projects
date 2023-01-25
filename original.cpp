/*
 * Video Link:
 * https://youtu.be/qlF-lQsU8JU
 */

int red = 7;
int green = 6;
int blue = 5;

void setup() {
    // put your setup code here, to run once:
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    changeColor(255, 255, 255); // white
    changeColor(255, 0, 0); // red
    changeColor(0, 0, 255); // blue
    changeColor(0, 255, 0); // green
    changeColor(255, 0, 255); // magenta
    changeColor(255, 255, 0); // yellow
    changeColor(250, 100, 250); // pink
    changeColor(102, 0, 102); // purple
}

/** 
 * Sets the LED color using RGB values, fading in and out
 * @param r analog PWM value for red (0-255)
 * @param g analog PWM value for green (0-255)
 * @param b analog PWM value for blue (0-255)
 */
void changeColor(int r, int g, int b) {
    // determine max value
    int maxVal = max(r, max(g, b));
    // fade in
    for (int i = 0; i < maxVal; i++) {
        if (i < r) {
            analogWrite(red, i);
        }
        if (i < g) {
            analogWrite(green, i);
        }
        if (i < b) {
            analogWrite(blue, i);
        }
        delay(1);
    }
    // just in case
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    delay(1000);
    // fade out
    for (int i = maxVal; i > 0; i--) {
        if (r > 0) {
            analogWrite(red, i);
        }
        if (g > 0) {
            analogWrite(green, i);
        }
        if (b > 0) {
            analogWrite(blue, i);
        }
        delay(2);
    }
    // insurance
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
    delay(500);
}