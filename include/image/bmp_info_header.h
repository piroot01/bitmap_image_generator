#define BMP_INFO_HEADER_INCLUDED
#ifdef BMP_INFO_HEADER_INCLUDED


#include "image/bmp_header_size.h"
#include <cstdint>
#include <array>


class BmpInfoHeader
{
public:
    explicit BmpInfoHeader(uint32_t width, uint32_t height);
    std::array<unsigned char, BMP_INFO_HEADER_SIZE> get() const;
    BmpInfoHeader& operator=(const BmpInfoHeader& source);

private:
    uint32_t _width;
    uint32_t _height;
    uint16_t _numberOfColorPlanes;
    uint32_t _bitsPerPixel;

public:
    friend class ImageWriter;

};


#endif
