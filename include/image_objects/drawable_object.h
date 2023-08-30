#ifndef DRAWABLE_OBJECTS_INCLUDED
#define DRAWABLE_OBJECTS_INCLUDED


#include "algorithms/algorithm.h"
#include "colors/color.h"


class DrawableObject
{
public:
    explicit DrawableObject(const std::shared_ptr<Algorithm> algorithm, const Color& color);
    virtual void generate() const = 0;

protected:
    const std::shared_ptr<Algorithm> _pAlgorithm;
    const Color& _color;

public:
    friend class QueueProcessor;

};


#endif
