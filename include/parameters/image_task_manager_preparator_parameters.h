#ifndef PREPARATOR_PARAMETERS_INCLUDED
#define PREPARATOR_PARAMETERS_INCLUDED


#include "parameters/parameters.h"
#include "image_objects/pixel_set.h"
#include <cstdint>
#include <vector>
#include <memory>


/**
* @class IdSizeIterator
* @brief class that holds the id of the iteraotor, iterator, and the size
*/
class IdSizeIterator
{
public:
    uint32_t id;
    PixelSet::const_iterator iterator;
    size_t size;

};


/**
* @class ImageTaskManagerPreparatorParameters
* @brief parameters for the ImageTaskManagerPreparator class
*/
class ImageTaskManagerPreparatorParameters : public Parameters
{
public:

    /**
    * @brief Default constructor
    */
    ImageTaskManagerPreparatorParameters();

    /**
    * @brief getChunkNum
    * @return uint32_t number of chunks that will be processed in the new threads
    */
    uint32_t getChunkNum() const;

    /**
    * @brief getChunkSize
    * @return uint32_t size of each chunk
    */
    uint32_t getChunkSize() const;

    /**
    * @brief getFinalChunkSize
    * @return uint32_t size of the final chunk that will be processed on the main thread
    */
    uint32_t getFinalChunkSize() const;

    
    /**
    * @brief getPixelSetIterators
    * @return std::vector<IdSizeIterator>& return the constant reference to the iterators
    */
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
