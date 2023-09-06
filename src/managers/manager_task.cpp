#include "managers/manager_task.h"
#include "chunk/image_chunk.h"
#include <algorithm>


std::shared_ptr<ImageChunk> ManagerTask::run(ManagerTaskParameters parameters, const uint32_t chunkNum)
{
    const auto chunkSize = (chunkNum != parameters._parameters->getChunkNum()) ? parameters._parameters->getChunkSize() : parameters._parameters->getFinalChunkSize();
    ImageChunk chunk(chunkSize, &parameters._pImage->getBaseColor());
    auto iterator = parameters._iterator.iterator;

    if (chunkNum == parameters._iterator.id)
    {
        const auto size = parameters._iterator.size;
        for (size_t i = 0; i < size; ++i)
        {
            chunk[(iterator->getPoint().x + iterator->getPoint().y * parameters._pImage->getHeight()) % chunkSize] = &iterator->getColor();
            iterator++;
        }
    }

    return std::make_shared<ImageChunk>(chunk);
}

// for debugging purposes

/*
std::shared_ptr<ImageChunk> ManagerTask::run(ManagerTaskParameters parameters, const uint32_t chunkNum)
{
    const auto chunkSize = (chunkNum != parameters._parameters->getChunkNum()) ? parameters._parameters->getChunkSize() : parameters._parameters->getFinalChunkSize();
    uint32_t pixelIndex = chunkNum * parameters._parameters->getChunkSize();
    ImageChunk chunk(chunkSize);
    auto iterator = parameters._iterator.iterator;

    std::cout << chunkNum << ':' << parameters._iterator.id << ':' << parameters._iterator.size << ':' << pixelIndex << " - \t";
    std::vector<char> v(chunkSize, '-');

    if (chunkNum == parameters._iterator.id)
    {
        for (uint32_t i = 0; i < parameters._iterator.size; ++i)
        {
            //std::cout << "\n|| " << iterator->getPoint().x << ":" << iterator->getPoint().y << "||\n";
            v[(iterator->getPoint().x + iterator->getPoint().y * parameters._pImage->getWidth()) % chunkSize] = 'O';
            iterator++;
        }
    }

    uint32_t i = 0;
    for (const auto& c : v)
    {
        std::cout << c;
        i++;
        if (i == parameters._pImage->getWidth())
        {
            std::cout << "\n\t\t";
            i = 0;
        }
    }
    std::cout << "\n";

    std::generate_n(chunk.begin(), chunkSize, [] { return &Colors::green; } );
    return std::make_shared<ImageChunk>(chunk);
}
*/
