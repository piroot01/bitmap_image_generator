#ifndef DRAWABLE_OBJECTS_QUEUE_INCLUDED
#define DRAWABLE_OBJECTS_QUEUE_INCLUDED


#include "image_objects/drawable_object.h"
#include <deque>


/**
* @class DrawableObjectsQueue
* @brief It is used to store all DrawableObject instances
*/
class DrawableObjectsQueue
{
public:

    /**
    * @brief Default constructor
    */
    DrawableObjectsQueue();

    /**
    * @brief push
    * @param drawableObject stores the pointer in the queue
    * @return void
    */
    void push(const std::shared_ptr<DrawableObject> drawableObject);

    /**
    * @brief pop
    * @return void
    */
    void pop();

    /**
    * @brief clear
    * @return void
    */
    void clear();

    /**
    * @brief begin
    * @return iterator
    */
    std::deque<std::shared_ptr<DrawableObject>>::const_iterator begin() const;

    /**
    * @brief end
    * @return iterator
    */
    std::deque<std::shared_ptr<DrawableObject>>::const_iterator end() const;

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
