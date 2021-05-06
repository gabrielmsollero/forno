#ifndef TempSensor_h
#define TempSensor_h

#include <Arduino.h>

class TempSensor
{
    public:
        TempSensor(int digitalPin);
        void setupTempSensor();
        float getTemp();

    private:
        int digitalPin;
};

#endif