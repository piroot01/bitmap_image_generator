#include "preparators/image_task_manager_preparator.h"


ImageTaskManagerPreparator::ImageTaskManagerPreparator(const size_t chunkBaseSize, const Image& image, const PixelSet& pixelSet) :
    _chunkBaseSize(chunkBaseSize), _pImage(&image), _pPixelSet(&pixelSet)
{
}


void ImageTaskManagerPreparator::calculateChunkSize()
{
    const uint32_t imageWidth = _pImage->getWidth();
    const uint32_t imageHeight = _pImage->getHeight();

    if (_chunkBaseSize > imageWidth * imageHeight)
        throw InvalidArgumentException("The chunkBaseSize is bigger than the image.");

    if (_chunkBaseSize <= imageWidth)
        _parameters._chunkSize = imageWidth;
    else if ((_parameters._chunkSize = _chunkBaseSize) > imageWidth)
        _parameters._chunkSize -= (_chunkBaseSize % imageWidth);
}


void ImageTaskManagerPreparator::calculateNumberOfChunks()
{
    // The multiplication may thow exception
    _parameters._chunkNum = (_pImage->getHeight() * _pImage->getWidth()) / _parameters._chunkSize;
}


void ImageTaskManagerPreparator::calculateFinalChunkSize()
{
    _parameters._finalChunkSize = _pImage->getHeight() * _pImage->getWidth() - _parameters.getChunkNum() * _parameters.getChunkSize();
}


void ImageTaskManagerPreparator::initializePixelSetIterators()
{
    const uint32_t imageWidth = _pImage->getWidth();
    const uint32_t chunkSize = _parameters._chunkSize;
    const uint32_t maxPixelIndex = _pImage->getHeight() * _pImage->getWidth();
    auto iterator = _pPixelSet->cbegin();
    uint32_t pixelIndex = 0;
    uint32_t size = 0;
    for (uint32_t chunkNum = 0; chunkNum < _parameters._chunkNum; ++chunkNum)
    {
        if (iterator != _pPixelSet->end())
            pixelIndex = iterator->getPoint().x + iterator->getPoint().y * imageWidth;
        size = 0;
        if (pixelIndex >= chunkNum * chunkSize and 
            pixelIndex < (chunkNum + 1) * chunkSize)
        {
            _parameters._pixelSetIterators.emplace_back(chunkNum, iterator, 0);
            while (pixelIndex < (chunkNum + 1) * chunkSize and iterator != _pPixelSet->end())
            {
                iterator++;
                size++;
                if (iterator != _pPixelSet->end())
                    pixelIndex = iterator->getPoint().x + iterator->getPoint().y * imageWidth;
            }
            _parameters._pixelSetIterators.back().size = size;
        }
    }

    if (_parameters._finalChunkSize)
    {
        size = 0;
        while (pixelIndex < maxPixelIndex)
        {
            iterator++;
            size++;
            pixelIndex = iterator->getPoint().x + iterator->getPoint().y * imageWidth;
        }
        _parameters._pixelSetIterators.emplace_back(_parameters._chunkNum, --iterator, size);
    }

    // for debigging purposes
    /*
    //std::cout << "Info: " << _parameters._chunkSize << ", " << _parameters._chunkNum << '\n';
    auto iter = _parameters._pixelSetIterators.begin()->iterator;
    for (uint32_t i = 0; i < _parameters._pixelSetIterators.size(); ++i)
    {
        std::cout << _parameters._pixelSetIterators[i].id << " : " << _parameters._pixelSetIterators[i].size << '\n';
        for (uint32_t j = 0; j < _parameters._pixelSetIterators[i].size; ++j)
        {
            std::cout << "[" << iter->getPoint().x << ", " << iter->getPoint().y << "]\n";
            iter++;
        }
    }
    */
}


void ImageTaskManagerPreparator::run()
{
    calculateChunkSize();
    calculateNumberOfChunks();
    calculateFinalChunkSize();
    initializePixelSetIterators();
}
