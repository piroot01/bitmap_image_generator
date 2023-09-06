#ifndef PREPARATOR_PARAMETERS_INCLUDED
#define PREPARATOR_PARAMETERS_INCLUDED


#include "parameters/parameters.h"
#include "image_objects/pixel_set.h"
#include <cstdint>
#include <vector>
#include <memory>


class IdSizeIterator
{
public:
    uint32_t id;
    PixelSet::const_iterator iterator;
    size_t size;

};


class ImageTaskManagerPreparatorParameters : public Parameters
{
public:
    ImageTaskManagerPreparatorParameters();
    uint32_t getChunkNum() const;
    uint32_t getChunkSize() const;
    uint32_t getFinalChunkSize() const;
    const std::vector<IdSizeIterator>& getPixelSetIterators() const;

private:
    uint32_t _chunkNum;
    uint32_t _chunkSize;
    uint32_t _finalChunkSize;

    std::vector<IdSizeIterator> _pixelSetIterators;

public:
    friend class ImageTaskManagerPreparator;

};


inline uint32_t ImageTaskManagerPreparatorParameters::getChunkNum() const
{
    return _chunkNum;
}


inline uint32_t ImageTaskManagerPreparatorParameters::getChunkSize() const
{
    return _chunkSize;
}


inline uint32_t ImageTaskManagerPreparatorParameters::getFinalChunkSize() const
{
    return _finalChunkSize;
}


inline const std::vector<IdSizeIterator>& ImageTaskManagerPreparatorParameters::getPixelSetIterators() const
{
    return _pixelSetIterators;
}


#endif
