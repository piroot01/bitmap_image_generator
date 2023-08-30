#include "processors/point_set_processor.h"


PointSetProcessor::PointSetProcessor(const std::shared_ptr<PointCollection> pPointCollection) :
    _pPointCollection(pPointCollection)
{
}


void PointSetProcessor::process(PixelSet& pixelSet, const Color& color) const
{
    auto iterator = _pPointCollection->rbegin();;
    uint32_t count = _pPointCollection->getCounter();
    for (uint32_t i = 0; i < count; ++i)
    {
        pixelSet.emplace(*iterator, color);
        iterator++;
    }
    _pPointCollection->resetCounter();
}
