#include <Arduino.h>
#include <../lib/TVoutfonts/font6x8.h>


#define FONT_WIDTH 6
#define FONT_HEIGHT 8


class TypeAndUntype : public Effect
{
    private:
        char* letters;
        int numLetters;
        int delay;
        int endDelay;
        String displayText = "";
        bool cursorShowing = false;
        int letterIndex = 0;
        int currentCenterX;
        int currentCenterY;

        void getTextCenterXY()
        {
            int length = this->displayText.length();
            if (this->cursorShowing) --length;

            this->currentCenterX = xCenter - (length * FONT_WIDTH) / 2;
            this->currentCenterY = yCenter - (FONT_HEIGHT / 2);
        }

    public:
        TypeAndUntype(EffectData variables, char* text, int numLetters, int delay, int endDelay) : Effect(variables)
        {
            this->letters = text;
            this->numLetters = numLetters;
            this->delay = delay;
            this->endDelay = endDelay;
        }

        void setup()
        {
            TV.select_font(font6x8);
        }

        void loop()
        {
            if (this->letterIndex >= this->numLetters)
            {
                TV.delay(1000);
                return;
            }

            this->displayText += this->letters[this->letterIndex];
            this->getTextCenterXY();

            TV.clear_screen();

            TV.set_cursor(this->currentCenterX, this->currentCenterY);

            String output = this->displayText + (this->cursorShowing ? "|" : "");
            TV.println(output.c_str());

            TV.println("A");
            TV.println("B");

            ++this->letterIndex;
            this->cursorShowing = !this->cursorShowing;

            TV.delay(this->delay);
        }
};