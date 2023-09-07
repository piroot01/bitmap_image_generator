#ifndef IMAGE_INCLUDED
#define IMAGE_INCLUDED


#include "writer/image_writer.h"
#include <cstdint>
#include <string>
#include <fstream>


/**
* @class Image
* @brief Class that represents the actual image
*/
class Image
{
public:

    /**
    * @brief Default constructor
    */
    Image();
    
    /**
    * @brief Constructor
    * @param width
    * @param height
    */
    Image(const uint32_t width, const uint32_t height);

    /**
    * @brief Constructor
    * @param fileName the name of the output file
    * @param width
    * @param height
    */
    Image(const std::string& fileName, const uint32_t width, const uint32_t height);

    /**
    * @brief Default destructor
    */
    ~Image();

    /**
    * @brief generateHeader
    */
    void generateHeader();

    /**
    * @brief appendPixel appends one pixel to the image
    * @warning Not recommended to use
    */
    void appendPixel(const Color& color);

    /**
    * @brief getWidth
    * @return uint32_t width of the image
    */
    uint32_t getWidth() const;

    /**
    * @brief getHeight
    * @return uint32_t height of the image
    */
    uint32_t getHeight() const;

    /**
    * @brief setBaseColor
    * @param const Color& color of the background
    * @return void
    */
    void setBaseColor(const Color& color);

    /**
    * @brief getBaseColor
    * @return const Color& returns the reference to the background color
    */
    const Color& getBaseColor() const;

private:
    void initializeImage();

private:
    std::string _fileName;
    uint32_t _width;
    uint32_t _height;

    Color _baseColor;

    BmpFileHeader _bmpHeader;
    BmpInfoHeader _bmpInfoHeader;
    std::unique_ptr<ImageWriter> _pImageWriter;

public:
    friend class ImageTaskManager;

};


inline uint32_t Image::getWidth() const
{
    return _width;
}


inline uint32_t Image::getHeight() const
{
    return _height;
}


inline void Image::setBaseColor(const Color& baseColor)
{
    _baseColor = baseColor;
}


inline const Color& Image::getBaseColor() const
{
    return _baseColor;
}


#endif
