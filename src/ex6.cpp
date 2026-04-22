#include "Arduino.h"

#define BLUE_PIN 14

int ledState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BLUE_PIN, OUTPUT);
  digitalWrite(BLUE_PIN, LOW);
  Serial.println("Serial control ready. Send 'B' to turn ON, 'b' to turn OFF");
}

void loop() {
  // Check if data is available on serial
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == 'B') {
      digitalWrite(BLUE_PIN, HIGH);
      ledState = 1;
    } 
    else if (command == 'b') {
      digitalWrite(BLUE_PIN, LOW);
      ledState = 0;
    }
    
    // Print status after each command
    Serial.print("BLUE=");
    Serial.println(ledState);
  }
}