#include "image/bmp_header.h"
#include "image/bmp_header_size.h"
#include <cstdint>


BmpHeader::BmpHeader(uint64_t pixelNum) :
    _sizeOfBitmapFile(pixelNum + BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE),
    _pixelDataOffset(BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE)
{
}

BmpHeader::BmpHeader(uint32_t width, uint32_t height) :
    _sizeOfBitmapFile(width * height + BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE),
    _pixelDataOffset(BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE)
{
}



