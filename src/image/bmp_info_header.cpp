#include "image/bmp_info_header.h"
#include "image/bmp_header_size.h"
#include <cstdint>

BmpInfoHeader::BmpInfoHeader(uint32_t width, uint32_t height, uint32_t horizontalResolution = 3780, uint32_t verticalResolution = 3780) :
    _sizeOfThisHeader(BMP_INFO_HEADER_SIZE),
    _width(width),
    _height(height),
    _numberOfColorPlanes(1),
    _colorDepth(24),
    _compressionMethod(0),
    _rawBitmapDataSize(0),
    _horizontalResolution(horizontalResolution),
    _verticalResolution(verticalResolution),
    _colorTableEntries(0),
    _importantColors(0)
{
}
