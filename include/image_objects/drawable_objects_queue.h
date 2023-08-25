#ifndef DRAWABLE_OBJECTS_QUEUE_INCLUDED
#define DRAWABLE_OBJECTS_QUEUE_INCLUDED


#include "drawable_objects.h"
#include <deque>


class DrawableObjectsQueue
{
public:
    DrawableObjectsQueue();

private:
    std::deque<DrawableObjects> _queue;

};




#endif
