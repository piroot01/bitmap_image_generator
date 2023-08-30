#ifndef POINT_SET_PROCESSOR_INCLUDED
#define POINT_SET_PROCESSOR_INCLUDED


#include "algorithms/point_collection.h"
#include "image_objects/pixel_set.h"
#include <memory>


class PointSetProcessor
{
public:
    explicit PointSetProcessor(const std::shared_ptr<PointCollection> pPointCollection);
    void process(PixelSet& pixelSet, const Color& color) const;

private:
    std::shared_ptr<PointCollection> _pPointCollection;

};


#endif
