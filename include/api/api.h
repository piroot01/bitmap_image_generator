#ifndef API_INCLUDED
#define API_INCLUDED


#include "image_objects/drawable_objects_queue.h"
#include "processors/queue_processor.h"
#include "image_objects/pixel_set.h"
#include "image/image.h"
#include "managers/image_task_manager.h"


/**
* @class Api
* @brief Templated class used as an interface for the program
*/
template<uint32_t ChunkSize = 0, uint32_t ThreadNum = 2>
class Api
{
public:

    /**
    * @brief Constructor
    * @param pImage raw pointer to an image object
    */
    explicit Api(const Image* pImage);

    /**
    * @brief Constructor
    * @param width width of the image
    * @param height height of the image
    */
    explicit Api(const uint32_t width, const uint32_t height);

    /**
    * @brief Constructor
    * @param fileName name of the output file
    * @param width width of the image
    * @param height height of the image
    */
    explicit Api(const std::string& fileName, const uint32_t width, const uint32_t height);

    /**
    * @brief Process the queue and generates the image
    * @param pQueue raw pointer to a queue
    */
    void process(const DrawableObjectsQueue* pQueue) const;

private:
    void checkQueue(const DrawableObjectsQueue& queue) const;

private:
    std::unique_ptr<Image> _pImage;

};


template<uint32_t ChunkSize, uint32_t ThreadNum>
Api<ChunkSize, ThreadNum>::Api(const Image* pImage) :
    _pImage(std::make_unique<Image>(pImage))
{
    _pImage->generateHeader();
}


template<uint32_t ChunkSize, uint32_t ThreadNum>
Api<ChunkSize, ThreadNum>::Api(const uint32_t width, const uint32_t height) :
    Api("output.bmp", width, height)
{
}


template<uint32_t ChunkSize, uint32_t ThreadNum>
Api<ChunkSize, ThreadNum>::Api(const std::string& fileName, const uint32_t width, const uint32_t height) :
    _pImage(std::make_unique<Image>(fileName, width, height))
{
    _pImage->generateHeader();
}

#include <iostream>
template<uint32_t ChunkSize, uint32_t ThreadNum>
void Api<ChunkSize, ThreadNum>::process(const DrawableObjectsQueue* pQueue) const
{
    try
    {
        checkQueue(*pQueue);
        PixelSet pixelSet;
        QueueProcessor queueProcessor(*pQueue);
        queueProcessor.process(pixelSet);
        ImageTaskManager manager(ChunkSize, *_pImage, pixelSet);
        manager.setConcurrentThreadNum(ThreadNum);
        manager.run();
    }
    catch (Exception& exception)
    {
        throw exception;
    }
}


template<uint32_t ChunkSize, uint32_t ThreadNum>
void Api<ChunkSize, ThreadNum>::checkQueue(const DrawableObjectsQueue& queue) const
{
    for (const auto& object : queue)
        object->check(_pImage->getWidth(), _pImage->getHeight());
}

#endif
