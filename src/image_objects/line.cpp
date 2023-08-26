#include "image_objects/line.h"


Line::Line(const Point& start, const Point& end, const Color& color) :
    _start(start), _end(end), _color(color)
{
}


Line::Line(const Point& start, const Point& end, const Color& color, const std::shared_ptr<LineAlgorithm> pLineAlgorithm) :
    _pLineAlgorithm(pLineAlgorithm), _start(start), _end(end), _color(color)
{
}

void Line::run() const
{
    _pLineAlgorithm->assignParameters(_start, _end);
    _pLineAlgorithm->run();
}
