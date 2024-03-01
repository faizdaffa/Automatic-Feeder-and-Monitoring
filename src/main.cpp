#include <Arduino.h>
#include <ultrasonic.h>
#include <pH_sensor.h>
#include <motor.h>
#include <thermocouple.h>
#include <tds_sensor.h>

void setup()
{
  Serial.begin(9600);
  // ultrasonic_innit();
  // tds_innit();
  // motor_innit();
  Serial.println("Start");
  for (uint32_t i = 0; i < 1000; i++)
  {
    ph_voltage(read_ph_analog_avg(ph_pin, 1000));
  }
  Serial.println("End");
}

void loop()
{
  // ph_voltage(read_ph_analog_avg(ph_pin, 1000));
  // read_distance();
  // read_ph();
  // clockwise();
  // read_thermocouple();
  // read_tds();
  // delay(1000);
}