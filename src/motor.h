#include <Arduino.h>

const uint8_t relayPin = 23;
int relayState = HIGH;
unsigned long previousMillis = 0;
uint32_t onDuration = 0;
uint32_t timeOFF = 5000;
bool isRelayOn = false;
String motorState;
float kilogram = 0.4;

void motor_innit()
{
    pinMode(relayPin, OUTPUT);
}

void motor_feeder(uint16_t offDuration, float kg)
{
    onDuration = kg * 250000;
    unsigned long currentMillis = millis();
    if (isRelayOn)
    {
        if (currentMillis - previousMillis >= onDuration)
        {
            digitalWrite(relayPin, HIGH);
            isRelayOn = false;
            previousMillis = currentMillis;
        }
    }
    else
    {
        if (currentMillis - previousMillis >= offDuration)
        {
            digitalWrite(relayPin, LOW);
            isRelayOn = true;
            previousMillis = currentMillis;
        }
    }
    // unsigned long seconds = currentMillis / 1000;
    // Serial.println(isRelayOn);
    // Serial.println(String(seconds) + ":" + " timeON: " + String(onDuration) + " || timeOFF: " + String(offDuration));
}