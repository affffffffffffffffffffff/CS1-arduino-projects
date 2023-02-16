# arduino-projects
Hosts all the Arduino projects for 4th Period Advanced CS1 Spring 2023 with Armand Ramones.
* This does not include the board design. Cope.
* This code is provided as-is with no documentation. 
* Code provided in good faith. 
* Any copying for cheating/plagiarism reasons is expressly prohibited.

## Index
<details><summary>

### Cycle 4: 9 January 2023 - 24 February 2023

</summary>

```
├───sketch_jan13a
│   └───sketch_jan13a.ino
├───sketch_jan17a
│   └───sketch_jan17a.ino
├───sketch_jan18a
│   └───sketch_jan13a.ino
├───sketch_jan23a
│   ├───noLoopConstruct.cpp
│   ├───original.cpp
│   └───sketch_jan23a.ino
├───sketch_jan25a
│   └───sketch_jan25a.ino
├───sketch_jan27a
│   └───sketch_jan27a.ino
├───sketch_jan30a
│   └───sketch_jan30a.ino
├───sketch_jan31a
│   ├───pitches.h
│   ├───sketch_jan31a.ino
│   └───testingSongNotes.cpp
├───sketch_feb01a
│   ├───pitches.h
│   └───sketch_feb01a.ino
├───musicProj
│   ├───Music_020723_pd4.ino
│   ├───MusicImg1_020723_pd4.ino
│   └───MusicImg2_020723_pd4.ino
├───sketch_feb08a.ino
│   └───sketch_feb08a.ino
├───sketch_feb08b.ino
│   ├───sketch_feb08a.ino
│   ├───SR04.cpp
│   └───SR04.h
├───sketch_feb10a.ino
│   ├───sketch_feb10a.ino
│   ├───SR04.cpp
│   └───SR04.h
├───sketch_feb13a.ino
│   └───sketch_feb13a.ino
├───sketch_feb14a.ino
│   ├───IRremote.cpp
│   ├───IRremote.h
│   ├───IRremoteInt.h
│   └───sketch_feb14a.ino
├───sketch_feb14b.ino
│   └───sketch_feb14b.ino
├───sketch_feb15a.ino
│   ├───LEDControl.cpp
│   ├───LEDControl.h
│   └───sketch_feb15a.ino
└───sketch_feb15b.ino
    ├───LEDControl.cpp
    ├───LEDControl.h
    └───sketch_feb15b.ino
```

</details>
<details><summary>

### Cycle 5: 27 February 2023 - 14 April 2023

</summary>

```
null
```

</details>
<details><summary>

### Cycle 6: 17 April 2023 - 31 May 2023

</summary>

```
null
```

</details>

## Projects
### jan13a
Two simple blinking LEDs.
### jan17a
Five LEDs that "crawl" across the prototype board. Two LEDs are on at a time.
### jan18a
Four LEDs based on timing data, syncing with timing tables in Excel.
### jan23a
Cycles through different colors, fading in and out.
`noLoopConstruct.cpp` attempts to recreate `original.cpp`/`sketch_jan23a.ino` without using any loop constructs.
> Besides control flow, modulus is another viable solution. 
### jan25a
Four LEDs based on timing data, syncing with timing tables in Excel, again.
### jan27a
Digital input with two buttons. One button turns the LED on, and one button turns the LED off.
### jan30a
Digital input with two buttons, again. One button simultaneously turns the LED on and speaker off, and one button simultaneously turns the LED off and speaker on.
### jan31a
Playing a passive buzzer. The melody is terrible, but it sets up the infrastructure code.
### feb01a
Using the infrastructure code from `sketch_jan31a.ino` and the composition from `testingSongNotes.cpp`, the melody of “我和我的祖国” ("My People, My Country") is played, syncing each note played with a pair of LED lights lighting up.
### musicProj
Final files submitted for the music project mentioned in `feb01a`. The header file was not included as it was implied.
### feb08a
Make a servo move.
### feb08b
Read the output of an ultrasonic sensor.
### feb10a
Make a servo point to an LED that turns on, depending on the distance read by an ultrasonic sensor.
### feb13a
Display the output of a joystick, but it should be like a coordinate plane in the first quadrant only.
### feb14a
Receive IR signals and outpput to terminal.
### feb14b
Correspond the joystick position to one of 9 LEDs arranged in a cross shape.
### feb15a
Display a pattern using an LED Dot Matrix.
### feb15b
Have a phrase scroll across the LED Dot Matrix. Given phrase was "You are what you eat!"
