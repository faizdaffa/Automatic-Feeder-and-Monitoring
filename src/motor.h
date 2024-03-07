
#include <Arduino.h>

int enB = 23;
int in4 = 3;
int in3 = 1;
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