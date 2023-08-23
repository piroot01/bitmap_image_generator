#define IMAGE_INCLUDED
#ifdef IMAGE_INCLUDED


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

private:
    void initializeImage();

private:
    std::string _fileName;
    uint32_t _width;
    uint32_t _height;

    BmpFileHeader _bmpHeader;
    BmpInfoHeader _bmpInfoHeader;
    ImageWriter* _image;

};


#endif
