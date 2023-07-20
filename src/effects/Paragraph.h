// #include <Arduino.h>
// #include <TVoutfonts/font6x8.h>
// #ifndef EFFECT_H
// #define EFFECT_H
// #include <Effect.h>
// #endif

// class Paragraph : public Effect 
// {
//     private: 
//         String* texts;
//         int delay;
//         int padding;
//         unsigned int textIndex = 1;
//         bool cursorShown = false;
//         String* phrase;
//         const unsigned char* FONT = font6x8;
//         int x;
//         int y;

//         void updateXYVariables()
//         {
//             int charWidth = 0;
//             int charHeight = 0;

//             if (this->FONT == font6x8)
//             {
//                 charWidth = 6;
//                 charHeight = 8;
//             }

//             this->x = xCenter - (charWidth * this->phrase->length()) / 2;
//             this->y = yCenter - (charHeight / 2);
//         }

//         void typeRandomlySelectedPhrase()
//         {
//             Serial.println("typerandomlyselected");
            
//             int randIndex = random(0, this->texts->length());
//             this->phrase = &this->texts[randIndex];
//             Serial.print("phrase: ");
//             Serial.println(this->phrase->c_str());
            

//             String visible = (*this->phrase).substring(0, this->textIndex) + (this->cursorShown ? "|" : "");
//             Serial.println(String("visible: ").concat(visible));

//             this->updateXYVariables();

//             Serial.println(visible.c_str());
//             Serial.println(this->x);
//             Serial.println(this->y);

//             TV.println(this->x, this->y, visible.c_str());

//             if (this->textIndex > this->phrase->length())
//             {
//             }
//             else 
//             {
//                 ++this->textIndex;
//             }
//         }

//     public: 
//         Paragraph(EffectSharedData variables, char* texts, int delay) : Effect(variables) 
//         {
            
//             this->texts = texts;
//             // this->texts = texts->copy();
//             this->delay = delay;
//         }

//         void setup()
//         {
//             TV.select_font(FONT);
//         }

//         void loop()
//         {
//             TV.clear_screen();

//             typeRandomlySelectedPhrase();

//             cursorShown = !cursorShown;
//             TV.delay(this->delay);
//         }
// };