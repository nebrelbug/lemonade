// ArduinoSound - Version: 0.2.0
#include <ArduinoSound.h>

// ArduinoHttpClient - Version: 0.3.1
#include <ArduinoHttpClient.h>

// ArduinoCloud - Version: 1.0.1
#include <ArduinoCloud.h>

int buttonPin = 2;     // the number of the pushbutton pin
const int fullSpeed = 255;  // how bright the LED is
const int stops = 0;
const int left1 = 9;         // the PWM pin the motor is attached to
const int left2 = 
const int right1 =
const int right2 = 10;       // the PWM pin the motor is attached to
int buttonState = 0;         // variable for reading the pushbutton status

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (buttonState == LOW) {
    // turn LED on:
  digitalWrite(left, fullSpeed);
  digitalWrite(right, fullSpeed);
  } 
  else {
    // turn LED off:
  digitalWrite(left, stop);
  digitalWrite(right, stop);
  }
  
  
}
