#include <Effect.h>
#include <util/EffectUtil.h>

#include <effects/Circle.h>
#include <effects/Lines.h>
#include <effects/Typing.h>
#include <effects/Border.h>
#include <effects/Squares.h>
#include <effects/Equalizer.h>
#include <effects/Paragraph.h>
#include <effects/Pixels.h>
#include <effects/TypeAndUntype.h>

#define NUM_EFFECTS 8
#define NUM_TYPE_UNTYPE_PHRASES 2

class EffectEngine
{
    private:
        Effect* effects[NUM_EFFECTS] = {};
        int effectIndex = 0;
        Effect* currentEffect;

    public:
        EffectEngine(EffectData variables)
        {
            Effect* fx[NUM_EFFECTS] = { 
                new Circle(variables),
                new Lines(variables, 3, 100),
                new Typing(variables, "HELLO WORLD", 700),
                new Border(variables, 10),
                new Squares(variables, 10, 5, 100),
                new Equalizer(variables, 5, 15),
                new Pixels(variables, 50, 2, 150),
                new TypeAndUntype(variables, "YEET", 4, 250, 1000)
                // new Paragraph(variables, phrases, 200)
            };

            for (int i = 0; i < NUM_EFFECTS; ++i)
                effects[i] = fx[i];
        }

        void setEffectIndex(int index)
        {
            this->effectIndex = index;
            this->currentEffect = effects[index];
        }

        void setupEffect()
        {
            (*currentEffect).setup();
        }

        void runEffect()
        {
            (*currentEffect).loop();
        }
};