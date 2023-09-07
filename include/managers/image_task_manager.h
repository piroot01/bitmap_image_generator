#ifndef IMAGE_TASK_MANAGER_INCLUDED
#define IMAGE_TASK_MANAGER_INCLUDED


#include "preparators/image_task_manager_preparator.h"
#include <image/image.h>
#include <image_objects/pixel_set.h>
#include <thread>


/**
* @class ImageTaskManager
* @brief Class that is used to launch the threads and collect their data afterwards
*/
class ImageTaskManager
{
public:

    /**
    * @brief Constructor
    * @param chunkBaseSize this partially determines the size of the single chunk that will be processed by a thread
    * @param image
    * @param pixelSet the set filled with pixels ready to be drawn
    */
    explicit ImageTaskManager(const size_t chunkBaseSize, const Image& image, const PixelSet& pixelSet);

    /**
    * @brief setConcurrentThreadNum
    * @detail Sets the number of theads that will be launched concurrentely
    * @param count
    * @return void
    */
    void setConcurrentThreadNum(const uint32_t count);

    /**
    * @brief run
    * @return void
    */
    void run();

private:
    const Image* _pImage;
    const PixelSet* _pPixelSet;
    ImageTaskManagerPreparator _preparator;

    uint32_t _concurrentThreadCount;

};


inline void ImageTaskManager::setConcurrentThreadNum(const uint32_t count)
{
    _concurrentThreadCount = count;
}


#endif
