#ifndef TempControl_h
#define TempControl_h

#include <Arduino.h>
#include <TempSensor.h>
#include <DigitalOutput.h>
#include <Ports.h>

class TempControl
{
    public:
        void setupTempControl(int pinTemp1, int pinTemp2, int pinTemp3, int pinTemp4);
        void setSetPointTemp(float setPointTemp);
        void controlHeat();
        void updateTemp();
        void setResist();
        float getTemp();
        void getTemps(float &t1, float &t2, float &t3, float &t4)
        void getResistStatus();

    private:
        TempSensor *tempSensor1;
        TempSensor *tempSensor2;
        TempSensor *tempSensor3;
        TempSensor *tempSensor4;

        DigitalOutput *resist;

        float setPointTemp

        float temp1;
        float temp2;
        float temp3;
        float temp4;
        float temp;
};

#endif