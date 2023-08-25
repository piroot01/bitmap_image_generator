#include "image/image.h"


Image::Image() :
    Image(std::string("output.bmp"), 256, 256)
{
    initializeImage();
}


Image::Image(const uint32_t width, const uint32_t height) :
    Image(std::string("output.bmp"), width, height)
{
    initializeImage();
}


Image::Image(const std::string& fileName, const uint32_t width, const uint32_t height) :
    _fileName(fileName),
    _width(width),
    _height(height),
    _bmpHeader(_width, _height),
    _bmpInfoHeader(_width, _height)
{
    initializeImage();
}


Image::~Image()
{
    _pImageWriter->close();
    delete _pImageWriter;
}


void Image::generateHeader()
{
    _pImageWriter->writeHeader(_bmpHeader, _bmpInfoHeader);
}


void Image::appendPixel(const Color& color)
{
    _pImageWriter->writePixel(color);
}


void Image::initializeImage()
{
    _pImageWriter = new ImageWriter(_fileName);
    _pImageWriter->open();
}
