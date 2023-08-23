#define BMP_HEADER_INCLUDED
#ifdef BMP_HEADER_INCLUDED


#include <cstdint>


class BmpHeader
{
public:
    explicit BmpHeader(uint64_t pixelNum);
    explicit BmpHeader(uint32_t width, uint32_t height);

private:
    const char _bitmapSignatureBytes[2] = {'B', 'M'};
    uint64_t _sizeOfBitmapFile;
    uint8_t _pixelDataOffset;

};


#endif
