#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN 25
bool flag = false;  // Tracks LED state: false = OFF, true = ON

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(GREEN_LED_PIN, OUTPUT);  // GREEN LED
    pinMode(BUTTON_PIN, INPUT);  // Button (HIGH = not pressed, LOW = pressed)
}

/****************************************************/
void loop(void) 
{
    static bool lastButtonState = HIGH;  // Remember the previous button state (starts as HIGH/not pressed)
    bool buttonState = digitalRead(BUTTON_PIN);
    
    // Check for a button press: transition from HIGH (not pressed) to LOW (pressed)
    if (buttonState == LOW && lastButtonState == HIGH) {
        flag = !flag;  // Toggle the flag
        digitalWrite(GREEN_LED_PIN, flag ? HIGH : LOW);  // Update LED based on flag
        Serial.println(flag ? "GREEN ON" : "GREEN OFF");  // Print status
    }
    
    lastButtonState = buttonState;  // Update previous state for next loop
    delay(50);  // Debounce delay: prevents multiple triggers from button bouncing
}