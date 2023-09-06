#ifndef LINE_INCLUDED
#define LINE_INCLUDED

#include "parameters/line_parameters.h"
#include "image_objects/drawable_object.h"
#include "image_objects/point.h"
#include "colors/color.h"


class Line : public DrawableObject
{
public:
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const Point& start, const Point& end, const Color& color);
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const LineParameters& parameters, const Color& color);
    void generate() const override;

private:
    const LineParameters _parameters;

};


inline void Line::generate() const
{
    _pAlgorithm->run(&_parameters);
}


#endif
