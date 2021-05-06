#include <DigitalOutput.h>

DigitalOutput::DigitalOutput(int digitalPin, int initialValue = LOW)
{
    pinMode(digitalPin, OUTPUT);
    digitalWrite(digitalPin, initialValue);
    this->digitalPin = digitalPin;  
    invert = false; 
    isOnBool = false;

    if(initialValue == HIGH)
    {
        isOnBool = true;
    }
}

void DigitalOutput::invertOutput(bool invert)
{
    this->invert = invert; 
    isOnBool = !isOnBool; 
}

void DigitalOutput::on()
{
    isOnBool = true; 
    if(!invert)
    {
        digitalWrite(digitalPin, HIGH);
    }
    else if(invert)
    {
        digitalWrite(digitalPin, LOW);
    }
}

void DigitalOutput::off()
{
    isOnBool = false;
    if(!invert)
    {
        digitalWrite(digitalPin, LOW);
    }
    else if(invert)
    {
        digitalWrite(digitalPin, HIGH);
    }
}

bool DigitalOutput::isOn()
{
    return isOnBool; 
}