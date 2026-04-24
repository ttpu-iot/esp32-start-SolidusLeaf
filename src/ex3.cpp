#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(LIGHT_SENSOR_PIN, INPUT);  // Light sensor (analog input)
}


/****************************************************/
void loop(void) 
{
    int sensorValue = analogRead(LIGHT_SENSOR_PIN);  // Read the light sensor value
    Serial.println(sensorValue);  // Print the sensor value
    delay(500);  // Wait for 500 ms

}
