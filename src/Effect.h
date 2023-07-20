#include <TVout.h>
#include <EffectSharedData.h>

class Effect
{
    protected: 
        static TVout TV;
        static int width;
        static int height;
        static int xCenter;
        static int yCenter;

    public:
        Effect() { }
        Effect(EffectSharedData variables)
        {
            this->TV = variables.TV;
            this->width = variables.width;
            this->height = variables.height;
            this->xCenter = width / 2;
            this->yCenter = height / 2;
        }

        virtual void setup() { };
        virtual void loop() { };
};