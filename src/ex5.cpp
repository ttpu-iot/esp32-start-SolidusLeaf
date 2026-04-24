#include "Arduino.h"

#define YELLOW_LED_PIN 12
#define BUTTON_PIN 25
#define LIGHT_SENSOR_PIN 33
bool flag = false;  // Tracks LED state: false = OFF, true = ON
int lightSensorValue = 0;  // Stores the current light sensor value
/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);  // Button (HIGH = not pressed, LOW = pressed)
    pinMode(LIGHT_SENSOR_PIN, INPUT);  // Light sensor (analog input)
    pinMode(YELLOW_LED_PIN, OUTPUT);  // Yellow LED (output)

}

/****************************************************/
void loop(void) 
{
    static bool lastButtonState = HIGH;  // Remember the previous button state (starts as HIGH/not pressed)
    bool buttonState = digitalRead(BUTTON_PIN);
    lightSensorValue = analogRead(LIGHT_SENSOR_PIN);  // Read the light sensor value

    // Check for a button press
    if (buttonState == LOW && lastButtonState == HIGH) {
        flag = !flag;  // Toggle the flag
        Serial.print("Reading value: ");
        Serial.println(lightSensorValue);  // Print the current light sensor value
        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }
    
    lastButtonState = buttonState;  // Update previous state for next loop
    delay(50);  // Debounce delay: prevents multiple triggers from button bouncing
}
