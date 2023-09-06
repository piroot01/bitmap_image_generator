#include "processors/point_set_processor.h"


PointSetProcessor::PointSetProcessor() = default;


void PointSetProcessor::process(PixelSet& pixelSet, PointCollection* pPointCollection, const Color& color) const
{
    auto iterator = pPointCollection->rbegin();;
    uint32_t count = pPointCollection->getCounter();
    for (uint32_t i = 0; i < count; ++i)
    {
        pixelSet.emplace(*iterator, color);
        iterator++;
    }
    pPointCollection->resetCounter();
}
