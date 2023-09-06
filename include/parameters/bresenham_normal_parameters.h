#ifndef BRESENHAM_NORMAL_PARAMETERS_INCLUDED
#define BRESENHAM_NORMAL_PARAMETERS_INCLUDED


#include "parameters/line_parameters.h"


class BresenhamNormalParameters : public LineParameters
{
public:
    BresenhamNormalParameters(const Point& start, const Point& end);

public:
    friend class BresenhamNormal;

};


#endif
