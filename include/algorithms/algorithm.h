#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED


#include "parameters/parameters.h"
#include "algorithms/point_collection.h"
#include <memory>


class Algorithm
{
public:
    explicit Algorithm(const std::shared_ptr<PointCollection> pPointCollection);
    virtual void run(const Parameters* parameters) = 0;

protected:
    std::shared_ptr<PointCollection> _pPointCollection;

public:
    friend class QueueProcessor;

};


#endif
