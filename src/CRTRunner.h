#include <Arduino.h>
#include <TVout.h>
#include <EffectEngine.h>


class CRTRunner
{
    private:
        int baudRate;
        int width;
        int height;
        TVout TV;
        EffectEngine* engine;


    public:
        CRTRunner(int baudRate, int width, int height) 
        { 
            this->baudRate = baudRate;
            this->width = width;
            this->height = height;

            TV.begin(NTSC, this->width, this->height);

            EffectDataStructure variables = { TV, this->width, this->height };
            this->engine = new EffectEngine(variables);
        }


        void setEffect(int effectIndex)
        {
            this->engine->setEffect(effectIndex);
            // this->engine->loop();
        }


        void loop()
        {
            this->engine->loop();
        }
};

