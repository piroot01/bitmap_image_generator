#define IMAGE_WRITER_INCLUDED
#ifdef IMAGE_WRITER_INCLUDED


#include "writer/base_writer.h"
#include "image/bmp_file_header.h"
#include "image/bmp_info_header.h"
#include "colors/colors.h"


class ImageWriter : public BaseWriter
{
public:
    ImageWriter();
    //~ImageWriter();
    ImageWriter(const std::string& streamName);
    ImageWriter(const std::string&& streamName);
    void open() override;
    void writeHeader(const BmpFileHeader& bmpHeader, const BmpInfoHeader& bmpInfoHeader);
    void writePixel(const Color& color);

};


#endif
