#ifndef LINE_INCLUDED
#define LINE_INCLUDED

#include "parameters/line_parameters.h"
#include "image_objects/drawable_object.h"
#include "image_objects/point.h"
#include "colors/color.h"
#include "exception/exception.h"


class Line : public DrawableObject
{
public:
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const Point& start, const Point& end, const Color& color);
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const Point&& start, const Point&& end, const Color& color);
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const LineParameters& parameters, const Color& color);
    void generate() const override;
    void check(const uint32_t imageWidth, const uint32_t imageHeight) const override;

private:
    const LineParameters _parameters;

};


inline void Line::generate() const
{
    _pAlgorithm->run(&_parameters);
}


inline void Line::check(const uint32_t imageWidth, const uint32_t imageHeight) const
{
    if (_parameters._start.x >= imageWidth or
        _parameters._start.y >= imageHeight or
        _parameters._end.x >= imageWidth or
        _parameters._end.y >= imageWidth)
        throw InvalidArgumentException("The line endpoints are not within the image boundaries.");
}

#endif
