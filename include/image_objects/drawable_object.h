#ifndef DRAWABLE_OBJECTS_INCLUDED
#define DRAWABLE_OBJECTS_INCLUDED


#include "algorithms/algorithm.h"


class DrawableObject
{
public:
    explicit DrawableObject(const std::shared_ptr<Algorithm> algorithm);
    virtual void generate() const = 0;

protected:
    const std::shared_ptr<Algorithm> _pAlgorithm;

public:
    friend class QueueProcessor;

};


#endif
