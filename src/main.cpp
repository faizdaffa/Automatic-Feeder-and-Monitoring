#include <Arduino.h>
#include <ultrasonic.h>
#include <pH_sensor.h>
#include <motor.h>
#include <thermocouple.h>
#include <tds_sensor copy.h>
// #include <tds_sensor.h>

void setup()
{
  Serial.begin(9600);
  ph_innit();
  tds_innit();
  ultrasonic_innit();
  // motor_innit();
}

void loop()
{
  ph_value(read_ph_analog_avg(ph_pin, 1000));
  tds_value(read_tds_analog_avg(tds_pin, 1000));
  read_thermocouple();
  read_distance();
  // clockwise();
  Serial.println("pH: " + String(ph) + " || TDS: " + String(tds) + " || T: " + String(T) + " || Jarak: " + String(distance));
  delay(500);
}