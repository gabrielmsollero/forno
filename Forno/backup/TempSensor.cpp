#include <TempSensor.h>
#include <Ports.h>

/*    Max6675 Module  ==>   Arduino
 *    CS              ==>     D10
 *    SO              ==>     D12
 *    SCK             ==>     D13
 *    Vcc             ==>     Vcc (5v)
 *    Gnd             ==>     Gnd      */

void TempSensor::setupTempSensor()
{
    uint16_t v;
    pinMode(Ports::MAX6675_CS, OUTPUT);
    pinMode(Ports::MAX6675_SO, INPUT);
    pinMode(Ports::MAX6675_SCK, OUTPUT);
  
    digitalWrite(Ports::MAX6675_CS, LOW);
    delay(1);
}

float TempSensor::getTemp()
{
    // código para ler a temperatura vinda o conversor
}