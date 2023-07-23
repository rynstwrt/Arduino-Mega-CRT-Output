#include <Arduino.h>
#include <effects/Circle.h>
#include <effects/Lines.h>
#include <effects/Typing.h>
#include <effects/Border.h>
#include <effects/Pixels.h>


#define NUM_EFFECTS 5
#define NUM_TYPE_UNTYPE_PHRASES 2


class EffectEngine
{
    private:
        Effect* effects[NUM_EFFECTS] = {};
        int effectIndex = 0;
        Effect* currentEffect;
        unsigned long lastChangeTime = millis();
        const unsigned long TIME_BEFORE_CHANGE = 4000;


    public:
        EffectEngine(EffectDataStructure variables)
        {   
            Effect* fx[NUM_EFFECTS] = { 
                new Circle(variables, 30),
                new Lines(variables, 5, 10),
                new Typing(variables, "RYN WUZ HERE", 700),
                new Border(variables),
                new Pixels(variables, 50, 2, 50)
            };

            for (int i = 0; i < NUM_EFFECTS; ++i)
                effects[i] = fx[i];
        }


        void setEffect(int index) // and also run setup
        {
            this->effectIndex = index;
            this->currentEffect = effects[index];

            (*currentEffect).setup();
        }

        void loop()
        {
            (*currentEffect).loop();
        }
};