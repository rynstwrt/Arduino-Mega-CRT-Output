/*
    Connections for the Arduino Mega:
        SYNC -> 11
        VIDEO -> 29
        AUDIO -> 10

    A 75 ohm resistor may be needed between VID and GND 
    on the RCA plug for a very small subset of TVs.
*/


#include <Arduino.h>
#include <CRTRunner.h>
#include <util/EffectNames.h>

#define SERIAL_BAUD_RATE 500000
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 96


CRTRunner* runner = new CRTRunner(SERIAL_BAUD_RATE, DISPLAY_WIDTH, DISPLAY_HEIGHT);
int currentEffect = EffectNames::LINES;


void setup()
{   
    Serial.begin(SERIAL_BAUD_RATE);
    runner->setEffect(currentEffect);
}


void loop()
{
    runner->loop();
}