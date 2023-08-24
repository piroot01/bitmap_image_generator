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
    _image->close();
    delete _image;
}


void Image::generateHeader()
{
    _image->writeHeader(_bmpHeader, _bmpInfoHeader);
}


void Image::appendPixel(const Color& color)
{
    _image->writePixel(color);
}


void Image::initializeImage()
{
    _image = new ImageWriter(_fileName);
    _image->open();
}
