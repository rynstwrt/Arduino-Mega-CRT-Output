#include <Arduino.h>
#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif
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

        bool hasRun = false;

        void getTextCenterXY()
        {
            int length = this->displayText.length();

            this->currentCenterX = xCenter - (length * FONT_WIDTH) / 2;
            this->currentCenterY = yCenter - (FONT_HEIGHT / 2);
        }

    public:
        TypeAndUntype(EffectSharedData variables, char* text, int numLetters, int delay, int endDelay) : Effect(variables)
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
            // if (hasRun)
            // {
            //     TV.delay(this->delay);
            //     return;
            // }

            // if (this->letterIndex >= this->numLetters)
            // {
            //     // this->letterIndex = 0;
            //     // this->displayText = "";
            //     hasRun = true;
            //     return;
            // }

            this->displayText = this->displayText + this->letters[this->letterIndex];
            this->getTextCenterXY();

            TV.clear_screen();

            TV.set_cursor(this->currentCenterX, this->currentCenterY);
            TV.println(this->displayText.c_str());

            ++this->letterIndex;
            TV.delay(this->delay);
        }
};


// class TypeAndUntype : public Effect
// {
//     private:
//         String* texts;
//         String currentText;


//         bool isTyping;
//         int numStrings;
//         int delay;
//         int stringIndex = 0;
//         // int letterIndex = 0;

//         void drawCenterText()
//         {
//             int x = xCenter - (6 * this->currentText.length()) / 2;
//             int y = yCenter - (8 / 2);

//             TV.set_cursor(x, y);
//             TV.println(this->currentText.c_str());
//         }        


//     public:
//         TypeAndUntype(EffectSharedData variables, int numStrings, String strings[], int delay) : Effect(variables)
//         {
//             // Set variables
//             this->isTyping = true;
//             this->numStrings = numStrings;
//             this->delay = delay;

//             // Populate private class member "String* texts"
//             this->texts = strings;          
//             for (int i = 0; i < this->numStrings; ++i) 
//             {
//                 String phrase = strings[i];
//                 this->texts[i] = phrase; 
//             }
//         }   

//         void setup()
//         {
//             // this->currentText = 
//         }

//         void loop()
//         {
//             for (int i = 0; i < this->numStrings; ++i)
//             {
//                 TV.clear_screen();

//                 this->currentText = this->texts[i];
//                 this->drawCenterText();

//                 TV.delay(500);
//             }

//             TV.delay(this->delay);
//         }
// };