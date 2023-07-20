#ifndef EFFECT_H
#define EFFECT_H
#include <Effect.h>
#endif

class SpacedShapes : public Effect
{
    private:
        int shapeWidth, shapeHeight = 0;

        void drawShapes()
        {
            int numPossibleShapesX = width / shapeWidth;
            int totalSpacingX = width - numPossibleShapesX * this->shapeWidth;
            int marginX = totalSpacingX / (numPossibleShapesX + 1);

            int numPossibleShapesY = height / shapeHeight;
            int totalSpacingY = height - numPossibleShapesY * this->shapeHeight;
            int marginY = totalSpacingY / (numPossibleShapesY + 1);

            for (int y = 0; y < numPossibleShapesY; ++y)
            {
                for (int x = 0; x < numPossibleShapesX; ++x)
                {
                }
            }
        }

    public:
        SpacedShapes(EffectData variables, int shapeWidth, int shapeHeight)
        {
            this->shapeWidth = shapeWidth;
            this->shapeHeight = shapeHeight;
        }

        void setup()
        {
            this->drawShapes();
        }

        void loop()
        {
            TV.delay(1000);
        }
};