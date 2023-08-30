#include "processors/queue_processor.h"
#include "image_objects/pixel_set.h"


QueueProcessor::QueueProcessor(const DrawableObjectsQueue& queue, const std::shared_ptr<PointCollection> pPoinCollection) :
    _pointSetProcessor(pPoinCollection), _queue(&queue), _pPointCollection(pPoinCollection)
{
}


void QueueProcessor::process(PixelSet& pixelSet) const
{
    for (const auto& iterator : *_queue)
    {
        iterator->generate();
        _pointSetProcessor.process(pixelSet, iterator->_color);
    }
}
