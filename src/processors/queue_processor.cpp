#include "processors/queue_processor.h"


QueueProcessor::QueueProcessor() = default;


QueueProcessor::QueueProcessor(const DrawableObjectsQueue& queue) :
    _queue(&queue)
{
}


void QueueProcessor::process() const
{
    for (const auto& iterator : *_queue)
    {
        iterator->generate();
    }
}
