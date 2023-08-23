#define BMP_INFO_HEADER_INCLUDED
#ifdef BMP_INFO_HEADER_INCLUDED


#include <cstdint>


class BmpInfoHeader
{
public:
    explicit BmpInfoHeader(uint64_t pixelNum);
    explicit BmpInfoHeader(uint32_t width, uint32_t height);

private:
    uint32_t _sizeOfThisHeader;
    int32_t _width;
    int32_t _height;
    uint16_t _numberOfColorPlanes;
    uint16_t _colorDepth;
    uint32_t _compressionMethod;
    uint32_t _rawBitmapDataSize;
    int32_t _horizontalResolution;
    int32_t _verticalResolution;
    uint32_t _colorTableEntries;
    uint32_t _importantColors;

};


#endif
