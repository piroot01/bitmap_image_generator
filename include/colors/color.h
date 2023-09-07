#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED


#include <cstdint>


/**
* @class Color
* @brief It stores color as three 8-bit values red, green and blue
*/
class Color
{
public:

    /**
    * @brief Default constructor
    * @param red
    * @param green
    * @param blue
    */
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
