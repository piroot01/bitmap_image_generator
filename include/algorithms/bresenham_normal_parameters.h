#ifndef BRESENHAM_NORMAL_PARAMETERS_INCLUDED
#define BRESENHAM_NORMAL_PARAMETERS_INCLUDED


#include "algorithms/line_parameters.h"


class BresenhamNormalParameters : public LineParameters
{
public:
    BresenhamNormalParameters(const Point& start, const Point& end);

public:
    friend class BresenhamNormal;

};


#endif
