#define BMP_INFO_HEADER_INCLUDED
#ifdef BMP_INFO_HEADER_INCLUDED


#include <cstdint>


class BmpInfoHeader
{
public:
    explicit BmpInfoHeader(uint32_t width, uint32_t height, uint32_t horizontalResolution, uint32_t verticalResolution);

private:
    uint32_t _sizeOfThisHeader;
    uint32_t _width;
    uint32_t _height;
    uint16_t _numberOfColorPlanes;
    uint16_t _colorDepth;
    uint32_t _compressionMethod;
    uint32_t _rawBitmapDataSize;
    uint32_t _horizontalResolution;
    uint32_t _verticalResolution;
    uint32_t _colorTableEntries;
    uint32_t _importantColors;

};


#endif
