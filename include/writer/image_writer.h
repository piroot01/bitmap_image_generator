#ifndef IMAGE_WRITER_INCLUDED
#define IMAGE_WRITER_INCLUDED


#include "writer/base_writer.h"
#include "chunk/image_chunk.h"
#include "image/bmp_file_header.h"
#include "image/bmp_info_header.h"
#include "colors/colors.h"


/**
* @class ImageWriter
* @brief It is used to write to a file
*/
class ImageWriter : public BaseWriter
{
public:

    /**
    * @brief Default constructor
    */
    ImageWriter();

    /**
    * @brief Constructor
    * @param streamName
    */
    ImageWriter(const std::string& streamName);

    /**
    * @brief open opens the stream
    * @return void
    */
    void open() override;

    /**
    * @brief writeHeader
    * @param bmpFileHeader
    * @aram bmpInfoHeader
    * @return void
    */
    void writeHeader(const BmpFileHeader& bmpFileHeader, const BmpInfoHeader& bmpInfoHeader);

    /**
    * @brief writePixel
    * @param color
    * @return void
    */
    void writePixel(const Color& color);

    /**
    * @brief writeImageChunk
    * @param chunk
    * @return void
    */
    void writeImageChunk(const ImageChunk* chunk);

};


#endif
