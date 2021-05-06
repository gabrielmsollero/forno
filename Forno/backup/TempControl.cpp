#include <TempControl.h>

void TempControl::setupTempControl(int pinTemp1, int pinTemp2, int pinTemp3, int pinTemp4)
{
    // instanciar sensores a partir da biblioteca do conversor

    tempSensor1 = new TempSensor(Ports::PIN_TEMP_1);
    tempSensor2 = new TempSensor(Ports::PIN_TEMP_2);
    tempSensor3 = new TempSensor(Ports::PIN_TEMP_3);
    tempSensor4 = new TempSensor(Ports::PIN_TEMP_4);
    
    resist = new DigitalOutput(Ports::PIN_RELAY);

    setPointTemp = 600;
}

void TempControl::setSetPointTemp(float setPointTemp)
{
    this->setPointTemp = setPointTemp;
}

void TempControl::controlHeat()
{
    float temp = getTemp();
    bool heating;
    if(temp > setPointTemp + 2) {
        resist->off();
        heating = true;
    } else if(temp)
}