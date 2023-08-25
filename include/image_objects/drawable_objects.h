#ifndef DRAWABLE_OBJECTS_INCLUDED
#define DRAWABLE_OBJECTS_INCLUDED


#include "drawable_objects_queue.h"
#include <iterator>


class DrawableObject
{
public:
    DrawableObject();
    virtual void associateAlgorithm(const Algorithm& algorithm) const;
    virtual void run();

protected:
    std::deque<Pixel>* _pStorage; 

};


#endif
