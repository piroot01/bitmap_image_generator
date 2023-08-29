#ifndef IMAGE_INCLUDED
#define IMAGE_INCLUDED


#include "writer/image_writer.h"
#include <cstdint>
#include <string>
#include <fstream>


class Image
{
public:
    Image();
    Image(const uint32_t width, const uint32_t height);
    Image(const std::string& fileName, const uint32_t width, const uint32_t height);
    ~Image();
    void generateHeader();
    void appendPixel(const Color& color);
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    void setBaseColor(const Color& color); 

private:
    void initializeImage();

private:
    std::string _fileName;
    uint32_t _width;
    uint32_t _height;

    Color _baseColor;

    BmpFileHeader _bmpHeader;
    BmpInfoHeader _bmpInfoHeader;
    ImageWriter* _pImageWriter;

public:
    friend class ImageProcessor;

};


inline uint32_t Image::getWidth() const
{
    return _width;
}


inline uint32_t Image::getHeight() const
{
    return _width;
}


inline void Image::setBaseColor(const Color& baseColor)
{
    _baseColor = baseColor;
}


#endif
