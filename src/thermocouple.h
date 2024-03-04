#include "max6675.h"

int thermoSO = 19;
int thermoCS = 2;
int thermoSCK = 18;
float T;

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void read_thermocouple()
{
    T = thermocouple.readCelsius();
    // Serial.println("T: " + String(T));
}