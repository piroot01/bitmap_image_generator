#ifndef IMAGE_PROCESSOR_PREPARATOR_INCLUDED
#define IMAGE_PROCESSOR_PREPARATOR_INCLUDED


#include "parameters/image_task_manager_preparator_parameters.h"
#include "image/image.h"


/**
* @class ImageTaskManagerPreparator
* @brief Prepares the data for ImageTaskManager
*/
class ImageTaskManagerPreparator
{
public:

    /**
    * @brief Constructor
    * @param chunkBaseSize
    * @param image
    * @param pixelSet
    */
    explicit ImageTaskManagerPreparator(const size_t chunkBaseSize, const Image& image, const PixelSet& pixelSet);

    /**
    * @brief run prepares the parameters
    * @return void
    */
    void run();

    /**
    * @brief getParameters
    * return const ImageTaskManagerPreparatorParameters&
    */
    const ImageTaskManagerPreparatorParameters& getParameters() const;

private:
    void calculateChunkSize();
    void calculateNumberOfChunks();
    void calculateFinalChunkSize();
    void initializePixelSetIterators();

private:
    uint32_t _chunkBaseSize;
    const Image* _pImage;
    const PixelSet* _pPixelSet;
    ImageTaskManagerPreparatorParameters _parameters;

};


inline const ImageTaskManagerPreparatorParameters& ImageTaskManagerPreparator::getParameters() const
{
    return _parameters;
}


#endif
