#ifndef BMP_HEADER_INCLUDED
#define BMP_HEADER_INCLUDED


#include <cstdint>
#include <array>
#include <image/bmp_header_size.h>


/**
* @class BmpFileHeader
* @brief Used to generate the file header of the image
*/
class BmpFileHeader
{
public:

    /**
    * @brief Default constructor
    * @param width
    * @param height
    */
    explicit BmpFileHeader(uint32_t width, uint32_t height);

    /**
    * @brief get
    * @return std::array<unsigned char, BMP_FILE_HEADER_SIZE> a complete file header
    */
    std::array<unsigned char, BMP_FILE_HEADER_SIZE> get() const;

    /** 
    * @brief Copy assign operator
    * @oaram BmpFileHeader&
    * @return BmpFileHeader&
    */
    BmpFileHeader& operator=(const BmpFileHeader& source);

private:
    const char _bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t _sizeOfBitmapFile;
    uint32_t _pixelDataOffset;

public:
    friend class ImageWriter;

};


#endif
