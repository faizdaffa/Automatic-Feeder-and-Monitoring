#include <Arduino.h>

const int trigPin = 17;
const int echoPin = 16;
long duration;
int pellets;

void ultrasonic_innit()
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
}

void read_distance()
{
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    pellets = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    // Serial.println("Distance: " + String(pellets));
}