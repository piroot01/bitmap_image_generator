#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED


#include "algorithms/parameters.h"
#include "image_objects/point_set.h"
#include <memory>


class Algorithm
{
public:
    explicit Algorithm(const std::shared_ptr<PointSet> pPointSet);
    virtual void run(const Parameters* parameters) = 0;

protected:
    std::shared_ptr<PointSet> _pPointSet;

};


#endif
