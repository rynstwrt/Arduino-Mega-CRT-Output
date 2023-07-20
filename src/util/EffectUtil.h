#include <Arduino.h>

class EffectUtil
{
    public:
        static int* getCenterTextCoords(String text, int width, int height, int fontWidth, int fontHeight)
        {
            int x = (width / 2) - (text.length() / 2 * fontWidth);
            int y = (height / 2) - (fontHeight / 2 * fontHeight);

            int result[2] = { x, y };
            return result;
        }
};