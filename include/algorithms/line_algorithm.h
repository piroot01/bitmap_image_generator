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
    explicit LineAlgorithm(std::shared_ptr<PointSet> pPointSet);
    void run() = 0;
    virtual void assignParameters(const Point& start, const Point& end) = 0;
//    virtual void assignParameters(const Point& start, const Point& end, const uint32_t lineThickness) = 0;

protected:
    Point _start;
    Point _end;
    //const uint32_t _lineThickness;

};


#endif
