#ifndef LINE_INCLUDED
#define LINE_INCLUDED


#include "image_objects/drawable_object.h"
#include "image_objects/point.h"
#include "colors/color.h"


class Line : public DrawableObject
{
public:
    explicit Line(const Point& start, const Point& end, const Color& color, const std::shared_ptr<Algorithm> algorithm);
    void generate() const override;

private:
    Point _start;
    Point _end;
    Color _color;

};


inline void Line::generate() const
{
    _pAlgorithm->run(_start, _end);
}


#endif
