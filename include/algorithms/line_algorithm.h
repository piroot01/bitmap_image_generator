#ifndef BRESENHAM_INCLUDED
#define BRESENHAM_INCLUDED


#include "algorithms/algorithm.h"
#include "image_objects/point.h"
#include "image_objects/point_set.h"
#include "colors/color.h"
#include <memory>


class LineAlgorithm : public Algorithm
{
public:
    explicit LineAlgorithm(const std::shared_ptr<PointSet> pPointSet);
    virtual void run() = 0;
//    virtual void assignParameters(const Point& start, const Point& end, const uint32_t lineThickness) = 0;


};


#endif
