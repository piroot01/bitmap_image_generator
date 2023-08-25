#include "image_objects/pixel.h"


Pixel::Pixel() :
    _point(),
    _color(Colors::white)
{
}


Pixel::Pixel(const Point& point, const Color& color) :
    _point(point),
    _color(color)
{
}


Pixel::Pixel(const uint32_t x, const uint32_t y, const Color& color) :
    _point(x, y),
    _color(color)
{
}
