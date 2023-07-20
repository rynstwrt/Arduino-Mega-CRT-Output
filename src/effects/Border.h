#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif

class Border : public Effect 
{
    public:
        Border(EffectData variables) : Effect(variables) { }

        void setup()
        {
            TV.clear_screen();
            TV.draw_rect(0, 0, width - 1, height - 1, WHITE);
        }

        void loop()
        {
            TV.delay(500);
        }
};