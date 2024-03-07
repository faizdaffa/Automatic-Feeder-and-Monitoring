float ph = 0;
int ph_pin = 36;

void ph_innit()
{
    pinMode(ph_pin, INPUT);
}

void read_ph_analog(int pin)
{
    uint16_t val = analogRead(pin);
    Serial.println(val);
}

float read_ph_analog_avg(int pin, uint32_t sample)
{
    float val = 0;
    for (uint32_t i = 0; i < sample; i++)
    {
        val += analogRead(pin);
    }
    val = val / sample;
    // Serial.println(val);
    return val;
}

void ph_value(float val)
{
    ph = 18.996592991130186 - (0.0041640039184704224 * val);
    // Serial.println(ph, 4);
}