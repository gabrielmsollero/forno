#ifndef DigitalOutput_h
#define DigitalOutput_h

#include <Arduino.h>

class DigitalOutput
{
    public:
        DigitalOutput(int digitalPin, int initialValue = LOW);
        void invertOutput(bool invert);
        void on();
        void off();
        bool isOn();

    private:
        int digitalPin;
        bool invert; 
        bool isOnBool; 
};

#endif



