#include "managers/image_task_manager.h"
#include "managers/manager_task.h"
#include "exception/exception.h"
#include "parameters/image_task_manager_preparator_parameters.h"
#include "thread_pool/thread_pool.h"
#include <iostream>


ImageTaskManager::ImageTaskManager(const size_t chunkBaseSize, const Image& image, const PixelSet& pixelSet) :
    _pImage(&image), _pPixelSet(&pixelSet), _preparator(chunkBaseSize, image, pixelSet), _concurrentThreadCount(2)
{
}


void ImageTaskManager::run()
{
    _preparator.run();
    const auto localParameters = _preparator.getParameters();
    auto iterators = localParameters.getPixelSetIterators();
    auto iterator = iterators.begin();
    auto chunkCount = localParameters.getChunkNum();

    ThreadPool<ProcessingStrategy::POP_FRONT> threadPool(_concurrentThreadCount);
    std::vector<std::future<std::shared_ptr<ImageChunk>>> futures(chunkCount);

    threadPool.init();

    for (uint32_t chunkNum = 0; chunkNum < chunkCount; ++chunkNum)
    {
        ManagerTaskParameters parameters(*iterator, std::move(localParameters), _pImage);
        futures[chunkNum] = threadPool.enqueue(ManagerTask::run, parameters, chunkNum);
        if (iterator != iterators.end() - 1 and (*iterator).id == chunkNum)
            iterator++;
    }

    for (auto& future : futures)
    {
        auto chunk = future.get();
        _pImage->_pImageWriter->writeImageChunk(chunk.get());
    }

    threadPool.shutdown();

    if (localParameters.getFinalChunkSize())
    {
        ManagerTaskParameters parameters(*iterator, localParameters, _pImage);
        _pImage->_pImageWriter->writeImageChunk(ManagerTask::run(parameters, chunkCount).get());
    }
}
