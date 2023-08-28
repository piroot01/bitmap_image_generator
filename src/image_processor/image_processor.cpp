#include "image_processor/image_processor.h"


ImageProcessor::ImageProcessor() = default;


ImageProcessor::ImageProcessor(const DrawableObjectsQueue& queue) :
    _queue(&queue)
{
}


void ImageProcessor::process() const
{
    for (const auto& iterator : *_queue)
    {
        iterator->generate();
    }
}
