#ifndef BRESENHAM_INCLUDED
#define BRESENHAM_INCLUDED


#include "image_objects/point.h"
#include "image_objects/pixel_set.h"
#include "colors/color.h"
#include <memory>


class Bresenham
{
public:
    explicit Bresenham(std::unique_ptr<PixelSet> pSet);
    void setPoints(const Point& start, const Point& end);
    void setColor(const Color& color);
    void run();

protected:
    std::unique_ptr<PixelSet> _pSet;

};


#endif
