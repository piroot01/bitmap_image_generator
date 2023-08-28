#ifndef IMAGE_PROCESSOR_INCLUDED
#define IMAGE_PROCESSOR_INCLUDED


#include "image_objects/drawable_objects_queue.h"


class ImageProcessor
{
public:
    ImageProcessor();
    ImageProcessor(const DrawableObjectsQueue& queue);
    void process() const;

private:
    const DrawableObjectsQueue* _queue;

};


#endif
