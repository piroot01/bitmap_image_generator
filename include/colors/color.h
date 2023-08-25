#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED


#include <cstdint>


class Color
{
public:
    explicit Color(uint8_t red, uint8_t green, uint8_t blue);
    uint8_t blue;
    uint8_t green;
    uint8_t red;

};


#endif
