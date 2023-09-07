#ifndef BMP_INFO_HEADER_INCLUDED
#define BMP_INFO_HEADER_INCLUDED


#include "image/bmp_header_size.h"
#include <cstdint>
#include <array>


/**
* @class BmpInfoHeader
* @brief Used to generate the info header of the image
*/
class BmpInfoHeader
{
public:

    /**
    * @brief Default constructor
    * @param width
    * @param height
    */
    explicit BmpInfoHeader(uint32_t width, uint32_t height);

    /**
    * @brief get
    * @return std::array<unsigned char, BMP_INFO_HEADER_SIZE> a complete info header
    */
    std::array<unsigned char, BMP_INFO_HEADER_SIZE> get() const;

    /** 
    * @brief Copy assign operator
    * @oaram BmpInfoHeader&
    * @return BmpInfoHeader&
    */
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
