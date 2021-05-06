#include <Arduino.h>
#include <DigitalOutput.h>
#include <Ports.h>
#include <Max6675.h>

#define TIME_LOOP_TEMP 3000

MAX6675 tempSensor1(Ports::SCK, Ports::CS_TEMP_1, Ports::MISO);
MAX6675 tempSensor2(Ports::SCK, Ports::CS_TEMP_2, Ports::MISO);
// MAX6675 tempSensor3(Ports::SCK, Ports::CS_TEMP_3, Ports::MISO);
// MAX6675 tempSensor4(Ports::SCK, Ports::CS_TEMP_4, Ports::MISO);

DigitalOutput csTemp1(Ports::CS_TEMP_1, LOW);
DigitalOutput csTemp2(Ports::CS_TEMP_2, LOW);
// DigitalOutput csTemp3(Ports::CS_TEMP_3, LOW);
// DigitalOutput csTemp4(Ports::CS_TEMP_4, LOW);

DigitalOutput resist(LED_BUILTIN, LOW);

float temp, t1, t2, t3, t4;

float setPointTemp = 20;

int state = 0;

unsigned long int prevMillis = 0;

float getAvgTemp(float t1, float t2, float t3, float t4)
{
    // return (t1 + t2 + t3 + t4)/4;
    return (t1 + t2)/2;
}

void readTemps(float &t1, float &t2, float &t3, float &t4)
{
    csTemp1.off();
    csTemp2.off();
    // csTemp3.off();
    // csTemp4.off();

    csTemp1.on();
    t1 = tempSensor1.readCelsius();
    csTemp1.off();

    csTemp2.on();
    t2 = tempSensor2.readCelsius();
    csTemp2.off();

    // csTemp3.on();
    // t3 = tempSensor3.readCelsius();
    // csTemp3.off();
    
    // csTemp4.on();
    // t4 = tempSensor4.readCelsius();
    // csTemp4.off();
    
}

void setupRoot()
{
    Serial.begin(9600); while(!Serial);

    csTemp1.invertOutput(true);
    csTemp2.invertOutput(true);
    // csTemp3.invertOutput(true);
    // csTemp4.invertOutput(true);
    digitalWrite(LED_BUILTIN, LOW);
}

void loopRoot()
{
    if(millis() > prevMillis + TIME_LOOP_TEMP) {

        prevMillis = millis();

        readTemps(t1, t2, t3, t4);

        temp = getAvgTemp(t1, t2, t3, t4);

        if(state == 0){
            resist.on();
            if(temp > setPointTemp + 2){
                state = 1;
            }
        }

        else if(state == 1){
            resist.off();
            if(temp < setPointTemp - 2){
                state = 0;
            }
        }

        Serial.println(String(millis()) + \
                                "\t" + String(t1) + \
                                "\t" + String(t2) + \
                                "\t" + String(t3) + \
                                "\t" + String(t4) + \
                                "\t" + String(temp) + \
                                "\t" + String(resist.isOn()));

        // delay(3000);

    }
}