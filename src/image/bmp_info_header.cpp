#include "image/bmp_info_header.h"


BmpInfoHeader::BmpInfoHeader(uint32_t width, uint32_t height) :
    _width(width),
    _height(height),
    _numberOfColorPlanes(1),
    _bitsPerPixel(3 * 8)
{
}


std::array<unsigned char, BMP_INFO_HEADER_SIZE> BmpInfoHeader::get() const
{
    std::array<unsigned char, BMP_INFO_HEADER_SIZE> bmpInfoHeader = {};
    bmpInfoHeader[0] = static_cast<unsigned char>(BMP_INFO_HEADER_SIZE);
    bmpInfoHeader[4] = static_cast<unsigned char>(_width);
    bmpInfoHeader[5] = static_cast<unsigned char>(_width >> 8);
    bmpInfoHeader[6] = static_cast<unsigned char>(_width >> 16);
    bmpInfoHeader[7] = static_cast<unsigned char>(_width >> 24);
    bmpInfoHeader[8] = static_cast<unsigned char>(_height);
    bmpInfoHeader[9] = static_cast<unsigned char>(_height >> 8);
    bmpInfoHeader[10] = static_cast<unsigned char>(_height>> 16);
    bmpInfoHeader[11] = static_cast<unsigned char>(_height >> 24);
    bmpInfoHeader[12] = static_cast<unsigned char>(_numberOfColorPlanes);
    bmpInfoHeader[14] = static_cast<unsigned char>(_bitsPerPixel);
    return bmpInfoHeader;
}


BmpInfoHeader& BmpInfoHeader::operator=(const BmpInfoHeader& source) = default;
