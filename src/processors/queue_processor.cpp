#include "processors/queue_processor.h"
#include "image_objects/pixel_set.h"


QueueProcessor::QueueProcessor(const DrawableObjectsQueue& queue) :
    _queue(&queue)
{
}


void QueueProcessor::process(PixelSet& pixelSet) const
{
    for (const auto& iterator : *_queue)
    {
        iterator->generate();
        _pointSetProcessor.process(pixelSet, iterator->_pAlgorithm->_pPointCollection.get(), iterator->_color);
    }
}
