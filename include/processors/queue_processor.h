#ifndef QUEUE_PROCESSOR_INCLUDED
#define QUEUE_PROCESSOR_INCLUDED


#include "processors/point_set_processor.h"
#include "image_objects/drawable_objects_queue.h"
#include "image_objects/pixel_set.h"


/**
* @class QueueProcessor
* @brief Processes the queue of DrawableObjects
*/
class QueueProcessor
{
public:

    /**
    * @brief Consttructor
    * @params queue
    */
    explicit QueueProcessor(const DrawableObjectsQueue& queue);

    /**
    * @brief process
    * @params pixelSet
    */
    void process(PixelSet& pixelSet) const;

private:
    const PointSetProcessor _pointSetProcessor;
    const DrawableObjectsQueue* _queue;

};


#endif
