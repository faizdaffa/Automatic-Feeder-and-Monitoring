float analog_ph;
int ph_pin = 27;

void read_ph()
{
    analog_ph = analogRead(ph_pin);
    Serial.println("analogPH: " + String(analog_ph));
}