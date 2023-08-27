#include "image_objects/line.h"


Line::Line(const std::shared_ptr<Algorithm> algorithm, const Point& start, const Point& end, const Color& color) :
    DrawableObject(algorithm), _parameters(start, end), _color(color)
{
}


Line::Line(const std::shared_ptr<Algorithm> algorithm, const LineParameters& parameters, const Color& color) :
    DrawableObject(algorithm), _parameters(parameters), _color(color)
{
}
