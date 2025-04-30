#include <Servo.h>

// Define the pin for the rain sensor
const int rainSensorPin = A0; // You can change this pin as per your wiring

// Define the pin for the servo motor
const int servoPin = 8; // You can change this pin as per your wiring

Servo myServo;

void setup() {
  // Set up the rain sensor pin as an input
  pinMode(rainSensorPin, INPUT);
  
  // Set up the servo motor
  myServo.attach(servoPin);
}

void loop() {
  // Read the state of the rain sensor
  int rainState = digitalRead(rainSensorPin);
  
  // If the rain sensor detects rain (LOW), rotate the servo motor continuously
  if (rainState == LOW) {
    myServo.write(180); // Rotate the servo motor to 90 degrees
  } else {
    // If no rain is detected, stop the servo motor
    myServo.write(0); // Rotate the servo motor to 0 degrees
  }
  
  // Add a small delay for stability
  delay(100);
}
