#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif

class Pixels : public Effect
{
    private:
        int numPixelsPerFrame;
        int pixelWidth;
        int delay;

    public:
        Pixels(EffectData variables, int numPixelsPerFrame, int pixelWidth, int delay) : Effect(variables)
        {
            this->numPixelsPerFrame = numPixelsPerFrame;
            this->pixelWidth = pixelWidth;
            this->delay = delay;
        }

        void loop()
        {
            TV.clear_screen();

            for (int i = 0; i < numPixelsPerFrame; ++i)
            {
                int x = random(0, this->width - this->pixelWidth);
                int y = random(0, this->height - this->pixelWidth);

                TV.draw_rect(x, y, this->pixelWidth, this->pixelWidth, WHITE, WHITE);
            }

            TV.delay(this->delay);
        }
};