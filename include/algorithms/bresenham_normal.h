#ifndef BRESENHAM_NORMAL_INCLUDED
#define BRESENHAM_NORMAL_INCLUDED


#include "algorithms/line_algorithm.h"


class BresenhamNormal : public LineAlgorithm
{
public:
    explicit BresenhamNormal(const std::shared_ptr<PointSet> pPointSet);

    void run(const Point& start, const Point& end);

};


#endif
