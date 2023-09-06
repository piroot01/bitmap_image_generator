#ifndef POINT_SET_PROCESSOR_INCLUDED
#define POINT_SET_PROCESSOR_INCLUDED


#include "algorithms/point_collection.h"
#include "image_objects/pixel_set.h"
#include <memory>


class PointSetProcessor
{
public:
    PointSetProcessor();
    void process(PixelSet& pixelSet, PointCollection* pPointCollection, const Color& color) const;

};


#endif
