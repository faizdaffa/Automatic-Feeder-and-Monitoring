
#include <Arduino.h>

int enB = 14;
int in4 = 13;
int in3 = 12;
int pwm = 255;

void motor_innit()
{
    // Set all the motor control pins to outputs
    pinMode(enB, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in3, OUTPUT);
}

void clockwise()
{
    analogWrite(enB, pwm);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);
}