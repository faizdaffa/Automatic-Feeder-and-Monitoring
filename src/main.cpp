#include <Arduino.h>
#include <ultrasonic.h>
#include <pH_sensor.h>
#include <thermocouple.h>
#include <tds_sensor copy.h>
#include <send_data.h>
#include <motor.h>

unsigned long previousTime = 0;

void setup()
{
  Serial.begin(9600);
  // connectWiFi();
  motor_innit();
  ph_innit();
  tds_innit();
  ultrasonic_innit();
  Serial.println("START");
}

void loop()
{
  ph_value(read_ph_analog_avg(ph_pin, 1000));
  tds_value(read_tds_analog_avg(tds_pin, 1000));
  read_thermocouple();
  motor_feeder(timeOFF, kilogram);
  sendData(ph, tds, temperature, pellets);

  unsigned long currentTime = millis();
  if (currentTime - previousTime >= 1000) 
  {
    read_distance();
    Serial.println("pH: " + String(ph) + " || TDS: " + String(tds) + " || T: " + String(temperature) + " || Pelet: " + String(pellets) + " || Motor: " + String(isRelayOn));
    previousTime = currentTime;
  }
}