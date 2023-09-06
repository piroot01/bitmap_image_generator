#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED


#include <cstdint>


class Color
{
public:
    explicit Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0);
    uint8_t blue;
    uint8_t green;
    uint8_t red;

};


inline bool operator==(const Color& lhs, const Color& rhs)
{
    return (lhs.blue == rhs.blue) and (lhs.green == rhs.green) and (lhs.red == rhs.red);
}


#endif
