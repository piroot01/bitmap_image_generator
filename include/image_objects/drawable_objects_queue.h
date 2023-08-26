#ifndef DRAWABLE_OBJECTS_QUEUE_INCLUDED
#define DRAWABLE_OBJECTS_QUEUE_INCLUDED


#include "image_objects/drawable_object.h"
#include <deque>

class DrawableObjectsQueue
{
public:
    DrawableObjectsQueue();
    void push(const DrawableObject& drawableObject);
    void pop();
    void clear();

private:
    std::deque<DrawableObject> _queue;

};


inline void DrawableObjectsQueue::push(const DrawableObject& drawableObject)
{
    _queue.push_back(drawableObject);
}


inline void DrawableObjectsQueue::clear()
{
    _queue.clear();
}


#endif
