#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif

class Squares : public Effect 
{
    private:
        int numSquares;
        int padding;
        int delay;

    public:
        Squares(EffectData variables, int numSquares, int padding, int delay) : Effect(variables) 
        {
            this->numSquares = numSquares;
            this->padding = padding;
            this->delay = delay;
        }

        void loop()
        {
            TV.clear_screen();

            for (int i = 1; i <= this->numSquares; ++i)
            {
                TV.clear_screen();

                int topLeftXY = this->padding * i;
                int adjustedWidth = width - this->padding * i * 2;
                int adjustedHeight = height - this->padding * i * 2;

                TV.draw_rect(topLeftXY, topLeftXY, adjustedWidth, adjustedHeight, WHITE);

                TV.delay(this->delay);
            }
        }
};