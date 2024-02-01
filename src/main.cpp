#include <Arduino.h>
#include <ultrasonic.h>
#include <pH_sensor.h>
#include <motor.h>
#include <thermocouple.h>

void setup()
{
  Serial.begin(9600);
  ultrasonic_setup();
  motor_innit();
}

void loop()
{
  // read_distance();
  // read_ph();
  // clockwise();
  read_thermocouple();
  delay(500);
}