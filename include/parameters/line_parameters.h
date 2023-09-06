#ifndef LINE_PARAMETERS_INCLUDED
#define LINE_PARAMETERS_INCLUDED


#include "parameters/parameters.h"
#include "image_objects/point.h"


class LineParameters : public Parameters
{
public:
    explicit LineParameters(const Point& start, const Point& end);

protected:
    const Point _start;
    const Point _end;

public:
    friend class LineAlgorithm;
    friend class Line;

};


#endif
