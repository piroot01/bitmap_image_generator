#ifndef IMAGE_PROCESSOR_INCLUDED
#define IMAGE_PROCESSOR_INCLUDED


#include "image_objects/drawable_objects_queue.h"


class QueueProcessor
{
public:
    QueueProcessor();
    QueueProcessor(const DrawableObjectsQueue& queue);
    void process() const;

private:
    const DrawableObjectsQueue* _queue;

};


#endif
