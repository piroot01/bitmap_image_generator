#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED


#include "image_objects/point_set.h"
#include <memory>


class Algorithm
{
public:
    explicit Algorithm(const std::shared_ptr<PointSet> pPointSet);
    virtual void run() = 0;

protected:
    std::shared_ptr<PointSet> _pPointSet;
};


#endif
