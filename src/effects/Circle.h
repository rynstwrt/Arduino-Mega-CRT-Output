#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif


class Circle : public Effect
{
    private:
        int delay;


    public:
        Circle(EffectDataStructure variables, int delay) : Effect(variables) 
        { 
            this->delay = delay;
        }
        
        
        void loop()
        {
            TV.clear_screen();

            static int radius;
            static bool increasing = true;

            int xCenter = width / 2;
            int yCenter = height / 2;

            TV.draw_circle(xCenter, yCenter, radius, WHITE);
            
            increasing ? ++radius : --radius;

            if (radius == 20)
                increasing = !increasing;
            else if (radius == 0)
                increasing = !increasing;

            TV.delay(this->delay);
        }
};