#include "image_objects/line.h"


Line::Line(const std::shared_ptr<Algorithm> algorithm, const Point& start, const Point& end, const Color& color) :
    DrawableObject(algorithm, color), _parameters(start, end)
{
}


Line::Line(const std::shared_ptr<Algorithm> algorithm, const LineParameters& parameters, const Color& color) :
    DrawableObject(algorithm, color), _parameters(parameters)
{
}
