#ifndef PIXEL_INCLUDED
#define PIXEL_INCLUDED


#include "image_objects/point.h"
#include "colors/colors.h"


class Pixel
{
public:
    Pixel();
    Pixel(const Point& point, const Color& color);
    Pixel(const uint32_t x, const uint32_t y, const Color& color);
    uint32_t getX() const;
    uint32_t getY() const;
    const Color& getColor() const;

private:
    Point _point;
    Color _color;

};


inline uint32_t Pixel::getX() const
{
    return _point.getX();
}


inline uint32_t Pixel::getY() const
{
    return _point.getY();
}


inline const Color& Pixel::getColor() const
{
    return _color;
}


#endif
