#ifndef LINE_INCLUDED
#define LINE_INCLUDED


#include "image_objects/drawable_object.h"


class Line : public DrawableObject
{
public:
    explicit Line(const Point& start, const Point& end, const Color& color);
    Line(const Point& start, const Point& end, const Color& color, const std::shared_ptr<LineAlgorithm> pAlgorithm);
    void run() const override;

private:
    std::shared_ptr<LineAlgorithm> _pLineAlgorithm;
    Point _start;
    Point _end;
    Color _color;

};


#endif
