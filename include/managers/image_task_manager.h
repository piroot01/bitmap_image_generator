#ifndef IMAGE_TASK_MANAGER_INCLUDED
#define IMAGE_TASK_MANAGER_INCLUDED


#include "preparators/image_task_manager_preparator.h"
#include <image/image.h>
#include <image_objects/pixel_set.h>
#include <thread>


class ImageTaskManager
{
public:
    explicit ImageTaskManager(const size_t chunkBaseSize, const Image& image, const PixelSet& pixelSet);
    void setConcurrentThreadNum(const uint32_t count);
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
