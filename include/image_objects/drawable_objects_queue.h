#ifndef DRAWABLE_OBJECTS_QUEUE_INCLUDED
#define DRAWABLE_OBJECTS_QUEUE_INCLUDED


#include "image_objects/drawable_object.h"
#include <deque>

class DrawableObjectsQueue
{
public:
    DrawableObjectsQueue();
    void push(const std::shared_ptr<DrawableObject> drawableObject);
    void pop();
    void clear();

private:
    std::deque<std::weak_ptr<DrawableObject>> _queue;

};


inline void DrawableObjectsQueue::push(const std::shared_ptr<DrawableObject> drawableObject)
{
    _queue.push_back(drawableObject);
}


inline void DrawableObjectsQueue::clear()
{
    _queue.clear();
}


#endif
