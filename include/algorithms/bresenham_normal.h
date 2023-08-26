#ifndef BRESENHAM_NORMAL_INCLUDED
#define BRESENHAM_NORMAL_INCLUDED


#include "algorithms/line_algorithm.h"


class BresenhamNormal : public LineAlgorithm
{
public:
    void assignParameters(const Point& start, const Point& end) override;
    void run() override;

};


#endif
