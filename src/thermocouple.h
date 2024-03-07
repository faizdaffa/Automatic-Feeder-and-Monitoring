#include "max6675.h"

int thermoSO = 19;
int thermoCS = 5;
int thermoSCK = 18;
float temperature = 0;

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void read_thermocouple()
{
    temperature = thermocouple.readCelsius();
    // Serial.println("T: " + String(T));
}