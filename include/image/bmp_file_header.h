#define BMP_HEADER_INCLUDED
#ifdef BMP_HEADER_INCLUDED


#include <cstdint>
#include <array>
#include <image/bmp_header_size.h>


class BmpFileHeader
{
public:
    explicit BmpFileHeader(uint32_t width, uint32_t height);
    std::array<unsigned char, BMP_FILE_HEADER_SIZE> get() const;
    BmpFileHeader& operator=(const BmpFileHeader& bmpHeader);

private:
    const char _bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t _sizeOfBitmapFile;
    uint32_t _pixelDataOffset;

public:
    friend class ImageWriter;

};


#endif
