/*
    Connections for the Arduino Mega:
        SYNC -> 11
        VIDEO -> 29
        AUDIO -> 10

    A 75 ohm resistor may be needed between VID and GND 
    on the RCA plug for a very small subset of TVs.
*/


#include <Arduino.h>
#include <TVout.h>
#include <EffectManager.h>

#define SERIAL_BAUD_RATE 500000
#define WIDTH 128
#define HEIGHT 96
#define ACTIVE_EFFECT_INDEX 7


TVout TV;
EffectManager* fxManager;


void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    TV.begin(NTSC, WIDTH, HEIGHT);

    EffectSharedData variables = { TV, WIDTH, HEIGHT };
    fxManager = new EffectManager(variables);
    fxManager->setEffectIndex(ACTIVE_EFFECT_INDEX);
    fxManager->setupEffect();
}


void loop()
{
    fxManager->runEffect();
}