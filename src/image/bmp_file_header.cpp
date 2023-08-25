#include "image/bmp_file_header.h"
#include "image/bmp_header_size.h"
#include <cstdint>


BmpFileHeader::BmpFileHeader(uint32_t width, uint32_t height) :
    _sizeOfBitmapFile(width * height + BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE),
    _pixelDataOffset(BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE)
{
}

std::array<unsigned char, BMP_FILE_HEADER_SIZE> BmpFileHeader::get() const
{
    std::array<unsigned char, BMP_FILE_HEADER_SIZE> bmpFileHeader = {};
    bmpFileHeader[0] = _bitmapSignatureBytes[0];
    bmpFileHeader[1] = _bitmapSignatureBytes[1];
    bmpFileHeader[2] = static_cast<unsigned char>(_sizeOfBitmapFile);
    bmpFileHeader[3] = static_cast<unsigned char>(_sizeOfBitmapFile >> 8);
    bmpFileHeader[4] = static_cast<unsigned char>(_sizeOfBitmapFile >> 16);
    bmpFileHeader[5] = static_cast<unsigned char>(_sizeOfBitmapFile >> 24);
    bmpFileHeader[10] = static_cast<unsigned char>(_pixelDataOffset);
    return bmpFileHeader;
}

BmpFileHeader& BmpFileHeader::operator=(const BmpFileHeader& source)
{
    if (this == &source)
        return *this;
    _sizeOfBitmapFile = source._sizeOfBitmapFile;
    _pixelDataOffset = source._pixelDataOffset;
    return *this;
}
