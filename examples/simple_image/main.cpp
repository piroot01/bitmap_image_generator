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
        image.appendPixel(Colors::black);

    return 0;
}
