#include "image/image.h"
#include <cstdint>


int main()
{
    uint32_t width = 512;
    uint32_t height = 512;
    uint32_t pixelNum = width * height;

    Image image(width, height);
    image.generateHeader();

    for(uint32_t i = 0; i < pixelNum; ++i)
    {
        if (((i % width) * (i / width)) % 10 == 0)
            image.appendPixel(Colors::black);
        else
            image.appendPixel(Colors::white);
    }

    return 0;
}
