#include <Arduino.h>
#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif
#include <../lib/TVoutfonts/fontALL.h>


class Typing : public Effect 
{
    private:
        String originalText;
        String text;
        bool firstText = true;
        int delay;


    public:
        Typing(EffectDataStructure variables, String text, int delay = 500) : Effect(variables) 
        {
            this->originalText = text;
            this->text = text;
            this->delay = delay;
        }


        void setup()
        {
            TV.select_font(font6x8);            
        }


        void loop()
        {
            TV.clear_screen();

            this->text = this->originalText;

            int textWidth = 6 * this->text.length(); 
            int textHeight = 8;

            int x = xCenter - textWidth / 2;
            int y = yCenter - textHeight / 2;

            TV.set_cursor(x, y);

            this->text = (firstText ? this->text : String(this->text + String("|")));
            TV.println(this->text.c_str());
            
            firstText = !firstText;

            TV.delay(this->delay);
        }
};