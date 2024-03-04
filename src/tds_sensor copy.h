#include <Arduino.h>
float tds;
int tds_pin = 26;

void tds_innit()
{
    pinMode(tds_pin, INPUT);
}

void read_tds_analog(int pin)
{
    uint16_t val = analogRead(pin);
    Serial.println(val);
}

float read_tds_analog_avg(int pin, uint32_t sample)
{
    float val = 0;
    for (uint32_t i = 0; i < sample; i++)
    {
        val += analogRead(pin);
    }
    val = val / sample;
    // Serial.println(val);
    return val;
}

void tds_value(float val)
{
    tds = 1.8543975663216088 + 0.4216608497232353 * val;
    // Serial.println(tds, 4);
}
/*
float analog_tds;
int tds_pin = 26;
int numReading = 100;

void tds_innit()
{
    pinMode(tds_pin, INPUT);
}

void mean_tds()
{
    float sum = 0; // Variable to store the sum of readings

    for (int i = 1; i <= numReading; i++)
    {
        analog_tds = analogRead(tds_pin);
        sum += analog_tds; // Add current reading to the sum
        Serial.println(String(i) + ". " + String(analog_tds));
        delay(500);
    }

    float mean = sum / numReading; // Calculate the mean value
    Serial.println("Mean value: " + String(mean));
}
*/