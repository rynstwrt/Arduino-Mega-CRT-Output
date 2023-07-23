#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif 


class Lines : public Effect
{
    private:
        int numLines;
        int delay;


        void drawRandomLine()
        {
            int point1X = random(width);
            int point1Y = random(height);

            int point2X = random(width);
            int point2Y = random(height);
            
            TV.draw_line(point1X, point1Y, point2X, point2Y, WHITE);
        }
            

    public:
        Lines(EffectDataStructure variables, int numLines, int delay) : Effect(variables) 
        { 
            this->numLines = numLines;
            this->delay = delay;
        }


        void loop()
        {
            TV.clear_screen();

            for (int i = 0; i < this->numLines; ++i)
            {
                this->drawRandomLine();
            }

            TV.delay(this->delay);
        }
};