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

    std::deque<std::shared_ptr<DrawableObject>>::const_iterator begin() const;
    std::deque<std::shared_ptr<DrawableObject>>::const_iterator end() const;
    //std::deque<std::shared_ptr<DrawableObject>>::iterator begin();
    //std::deque<std::shared_ptr<DrawableObject>>::iterator end();

private:
    std::deque<std::shared_ptr<DrawableObject>> _queue;

};


inline void DrawableObjectsQueue::push(const std::shared_ptr<DrawableObject> drawableObject)
{
    _queue.push_back(drawableObject);
}


inline void DrawableObjectsQueue::clear()
{
    _queue.clear();
}


inline std::deque<std::shared_ptr<DrawableObject>>::const_iterator DrawableObjectsQueue::begin() const
{
    return _queue.begin();
}


inline std::deque<std::shared_ptr<DrawableObject>>::const_iterator DrawableObjectsQueue::end() const
{
    return _queue.end();
}

/*
inline std::deque<std::shared_ptr<DrawableObject>>::iterator DrawableObjectsQueue::begin()
{
    return _queue.begin();
}


inline std::deque<std::shared_ptr<DrawableObject>>::iterator DrawableObjectsQueue::end()
{
    return _queue.end();
}
*/

#endif
