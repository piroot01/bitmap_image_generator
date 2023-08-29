#ifndef BRESENHAM_INCLUDED
#define BRESENHAM_INCLUDED


#include "algorithms/line_parameters.h"
#include "algorithms/algorithm.h"
#include "algorithms/point_collection.h"
#include "colors/color.h"
#include <memory>


class LineAlgorithm : public Algorithm
{
public:
    explicit LineAlgorithm(const std::shared_ptr<PointCollection> pPointCollection);
    virtual void run(const Parameters* pParameters) = 0;
//    virtual void assignParameters(const Point& start, const Point& end, const uint32_t lineThickness) = 0;


};


#endif
