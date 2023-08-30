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
    const Color& getColor() const;
    const Point& getPoint() const;

private:
    Point _point;
    const Color& _color;

public:
    friend bool operator<(const Pixel& lhs, const Pixel& rhs);
};


inline const Color& Pixel::getColor() const
{
    return _color;
}


inline const Point& Pixel::getPoint() const
{
    return _point;
}


inline bool operator<(const Pixel& lhs, const Pixel& rhs)
{
    return lhs._point < rhs._point;
}

#endif
