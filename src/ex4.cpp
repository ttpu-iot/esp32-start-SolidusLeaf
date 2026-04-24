#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define BLUE_LED_PIN 14
#define YELLOW_LED_PIN 12
#define LIGHT_SENSOR_PIN 33

int sensorValue = 0;
int thrs1 = 1023; // Threshold for low light
int thrs2 = 2047; // Threshold for medium light
int thrs3 = 3071; // Threshold for high light
int thrs4 = 4095; // Threshold for very high light

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT); // RED LED
    pinMode(GREEN_LED_PIN, OUTPUT); // GREEN LED
    pinMode(BLUE_LED_PIN, OUTPUT); // BLUE LED
    pinMode(YELLOW_LED_PIN, OUTPUT); // YELLOW LED
    pinMode(LIGHT_SENSOR_PIN, INPUT);  // Light sensor (analog input)
}


/****************************************************/
void loop(void) 
{
    sensorValue = analogRead(LIGHT_SENSOR_PIN);  // Read the light sensor value
    if (sensorValue < thrs1 && sensorValue >= 0) {
        digitalWrite(RED_LED_PIN, LOW); // Turn RED ON
        digitalWrite(GREEN_LED_PIN, LOW); // Turn GREEN OFF
        digitalWrite(BLUE_LED_PIN, HIGH); // Turn BLUE OFF
        digitalWrite(YELLOW_LED_PIN, LOW); // Turn YELLOW OFF
        Serial.println("BLUE");
    } else if (sensorValue >= thrs1+1 && sensorValue < thrs2) {
        digitalWrite(RED_LED_PIN, LOW); // Turn RED OFF
        digitalWrite(GREEN_LED_PIN, HIGH); // Turn GREEN ON
        digitalWrite(BLUE_LED_PIN, LOW); // Turn BLUE OFF
        digitalWrite(YELLOW_LED_PIN, LOW); // Turn YELLOW OFF
        Serial.println("GREEN");
    } else if (sensorValue >= thrs2+1 && sensorValue < thrs3) {
        digitalWrite(RED_LED_PIN, LOW); // Turn RED OFF
        digitalWrite(GREEN_LED_PIN, LOW); // Turn GREEN OFF
        digitalWrite(BLUE_LED_PIN, LOW); // Turn BLUE ON
        digitalWrite(YELLOW_LED_PIN, HIGH); // Turn YELLOW OFF
        Serial.println("YELLOW");
    } else if (sensorValue >= thrs3+1 && sensorValue < thrs4) {
        digitalWrite(RED_LED_PIN, HIGH); // Turn RED OFF
        digitalWrite(GREEN_LED_PIN, LOW); // Turn GREEN OFF
        digitalWrite(BLUE_LED_PIN, LOW); // Turn BLUE OFF
        digitalWrite(YELLOW_LED_PIN, LOW); // Turn YELLOW ON
        Serial.println("RED");
    } else {
        digitalWrite(RED_LED_PIN, HIGH); // Turn RED ON
        digitalWrite(GREEN_LED_PIN, HIGH); // Turn GREEN ON
        digitalWrite(BLUE_LED_PIN, HIGH); // Turn BLUE ON
        digitalWrite(YELLOW_LED_PIN, HIGH); // Turn YELLOW ON
        Serial.println("Something went wrong with the sensor reading!");
    }
    
}
