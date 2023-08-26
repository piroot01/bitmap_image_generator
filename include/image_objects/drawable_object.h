#ifndef DRAWABLE_OBJECTS_INCLUDED
#define DRAWABLE_OBJECTS_INCLUDED


#include "algorithms/line_algorithm.h"


class DrawableObject
{
public:
    DrawableObject();
    virtual void run() const = 0;

};


#endif
