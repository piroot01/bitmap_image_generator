#ifndef QUEUE_PROCESSOR_INCLUDED
#define QUEUE_PROCESSOR_INCLUDED


#include "processors/point_set_processor.h"
#include "image_objects/drawable_objects_queue.h"
#include "image_objects/pixel_set.h"


class QueueProcessor
{
public:
    explicit QueueProcessor(const DrawableObjectsQueue& queue, const std::shared_ptr<PointCollection> pPointCollection);
    void process(PixelSet& pixelSet) const;

private:
    const PointSetProcessor _pointSetProcessor;
    const DrawableObjectsQueue* _queue;
    const std::shared_ptr<PointCollection> _pPointCollection;

};


#endif
