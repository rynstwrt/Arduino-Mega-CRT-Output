#include <Arduino.h>
#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif

class Equalizer : public Effect
{
    private:
        int numBars;
        int barThickness;
        bool inProgress = false;

        void drawBar(int x, int barHeight)
        {
            TV.draw_rect(x, height - barHeight, this->barThickness, barHeight, WHITE);
        }

        void drawBars(int* heights)
        {            
            int maxBarThickness = width / this->numBars;
            if (this->barThickness > maxBarThickness)
                this->barThickness = maxBarThickness;

            int spaceUsed = this->barThickness * this->numBars;
            int remaining_space = width - spaceUsed; 
            int space_size = remaining_space / ((this->numBars) + 1);

            for (int i = 0; i < this->numBars; ++i)
            {
                // A B A B A
                // Is (this->barThickness * i) correct?
                this->drawBar((space_size * (i + 1)) + (this->barThickness * i), heights[i - 1]);
            }
        }

    public:
        Equalizer(EffectData variables, int numBars, int barThickness) : Effect(variables)
        {
            this->numBars = numBars;
            this->barThickness = barThickness;
        } 

        void setup()
        {
        }

        void loop()
        {
            TV.clear_screen();

            int randoms[this->numBars];
            for (int i = 0; i < this->numBars; ++i)
                randoms[i] = random(0, this->height);

            this->drawBars(randoms);

            TV.delay(1000);
        }
};