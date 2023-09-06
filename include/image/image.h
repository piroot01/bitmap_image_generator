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
    const Color& getBaseColor() const;

private:
    void initializeImage();

private:
    std::string _fileName;
    uint32_t _width;
    uint32_t _height;

    Color _baseColor;

    BmpFileHeader _bmpHeader;
    BmpInfoHeader _bmpInfoHeader;
    std::unique_ptr<ImageWriter> _pImageWriter;

public:
    friend class ImageTaskManager;

};


inline uint32_t Image::getWidth() const
{
    return _width;
}


inline uint32_t Image::getHeight() const
{
    return _height;
}


inline void Image::setBaseColor(const Color& baseColor)
{
    _baseColor = baseColor;
}


inline const Color& Image::getBaseColor() const
{
    return _baseColor;
}


#endif
