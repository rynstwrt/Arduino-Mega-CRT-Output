// #ifndef EFFECT_H
// #define EFFECT_H
// #include <Effect.h>
// #endif

class Border : public Effect 
{
    private:
        int padding;

    public:
        Border(EffectData variables, int padding) : Effect(variables) 
        {
            this->padding = padding;
        }

        void setup()
        {
            
            
        }

        void loop()
        {
            TV.clear_screen();

            TV.draw_rect(this->padding, this->padding, width - this->padding * 2, height - this->padding * 2, WHITE);

            TV.delay(500);
        }
};