#include <SoftwareSerial.h> // For bluetooth

#include <Wire.h> //For LCD
#include "rgb_lcd.h"

rgb_lcd lcd;
int rColour = 255;
int gColour = 255;
int bColour = 255;

SoftwareSerial bluetooth(0, 1); // RX, TX pins for Bluetooth module

// Ports
const int motionPin = 8; // PIR sensor
const int buzzerPin = 6; // Buzzer
const int buttonPin = 5;     // The button
const int ledPin =  4; // LED for the button

bool alarmStart = false;
bool alarmStart2 = false;
bool alarmStart3 = false;
// Values Changes
int motionValue = 0; // variable to store the motion sensor value
int detectionTime = 10; // variable to store the duration of the motion
int buttonState = 0; // variable to store the state of the button
int lastButtonState = LOW; // variable to store the previous state of the button
bool ledOn = false; // Track the state of the LED

void setup() {
  bluetooth.println("Welcome to the laptop security device system (NOT ARMED).");
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  bluetooth.begin(9600); // initialize Bluetooth communication at 9600 bits per second
  pinMode(motionPin, INPUT); // set the motionPin as an input
  pinMode(buzzerPin, OUTPUT); // set the buzzerPIn as an output
  pinMode(ledPin, OUTPUT); // set the ledPin as an output
  pinMode(buttonPin, INPUT); // set the buttonPin as an input

  //For the LCD:
  lcd.begin(16, 2);
  lcd.setRGB(rColour, gColour, bColour);
  lcd.print("Laptop Security Device. "); //First Message
  lcd.setCursor(0, 1);
  lcd.print("Click to begin.");
  lcd.setCursor(0, 0);
}

bool GetMotion(int motionPin, int detectionTime) {
  int numDetections = 0; // Initialize the number of consecutive detections to zero
  for (int i = 0; i < detectionTime; i++) {
    if (digitalRead(motionPin) == HIGH) { // If motion is detected
      numDetections++; // Increment the number of consecutive detections
      if (numDetections == 5) { // If there are five consecutive detections
        return true; // Motion detected
      }
      else if (numDetections == 3) { // If there are three consecutive detections
        delay(2000); // Wait for 2 seconds before checking again
      }
    } else if (digitalRead(motionPin) == LOW) {
      numDetections = 0;
    }
    delay(800); //delay of 800ms
  }
  return false; // Motion not detected within the specified detection time
}



void alarm(int secs) { // Sound the alarm for a number of seconds
  if (alarmStart == true){
    for (int i = 0; i < secs; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ALARM TRIGGERED !!!");
      tone(buzzerPin, 100, 250); // Play the high-pitched tone for 250ms
      lcd.setRGB(255, 0, 0);
      delay(150); // Wait for 250ms before playing the next tone
      tone(buzzerPin, 440, 250); // Play the low-pitched tone for 250ms
      lcd.setRGB(255, 0, 255);
      lcd.setCursor(0, 1);
      lcd.print("OWNER NOTIFIED");
      delay(150);
      lcd.clear();
    }
  }
}

void AD(int cc) {
  static bool cx = false;
  static bool cv = false;
  
  if (cc == 1 && !cx) {
    bluetooth.println("Alarm Disarmed");
    Serial.println("Alarm Disarmed");
    lcd.clear();
    lcd.setRGB(0, 255, 0);
    lcd.setCursor(0, 0);
    lcd.print("Alarm Disarmed.");
    cx = true;
  }
  else if (cc == 2 && !cv) {
    lcd.clear();
    lcd.print("Click to");
    lcd.setCursor(0, 1);
    lcd.print("turn on. ");
    lcd.setCursor(0, 0);
    lcd.setRGB(0, 255, 0);
    cv = true;
  }
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state
  if (buttonState != lastButtonState) { // Check if the button state has changed
    if (buttonState == HIGH && !ledOn) { // Button has been pressed and LED is off
      digitalWrite(ledPin, HIGH); // Turn on the LED
      ledOn = true;
    } else if (buttonState == HIGH && ledOn) { // Button has been pressed and LED is on
      digitalWrite(ledPin, LOW); // Turn off the LED
      ledOn = false;
    }
  }

  // Check if the LED is on
if (ledOn) { 
  if (ledOn && alarmStart2 == true){
  alarmStart3 = true;
  }
  bool gm = GetMotion(motionPin, detectionTime);
  if (gm && alarmStart) { // Check if motion is detected and the alarm is started
    Serial.println("Alarm Triggered. ");
    // Being Stolen Alert 
    bluetooth.println("Device is being Stolen! "); // send message to connected Bluetooth device
    // Sound the ALARM!!!
    alarm(5);
  }
}
else {
  alarmStart = true;
  if (alarmStart2 == true && alarmStart3 == true){
    AD(1);
  }
  else if (alarmStart2 == false){
    alarmStart2 = true;
    AD(2);
  }
}


  lastButtonState = buttonState; // Store the current button state for the next loop
  delay(10);
}
