#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED


#include "image_objects/point_set.h"
#include <memory>


class Algorithm
{
protected:
    explicit Algorithm(std::shared_ptr<PointSet> pPointSet);
    virtual ~Algorithm();
    virtual void run() = 0;

    std::shared_ptr<PointSet> _pPointSet;
};



#endif
