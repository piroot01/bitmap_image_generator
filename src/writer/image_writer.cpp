#include "writer/image_writer.h"
#include "image/bmp_header_size.h"
#include <iostream>


ImageWriter::ImageWriter() = default;


ImageWriter::ImageWriter(const std::string& streamName) :
    BaseWriter(streamName)
{
}


void ImageWriter::open()
{
    _stream.open(_streamName, std::ios::binary);
}


void ImageWriter::writeHeader(const BmpFileHeader& bmpHeader, const BmpInfoHeader& bmpInfoHeader)
{
    _stream.write(reinterpret_cast<const char*>(bmpHeader.get().data()), BMP_FILE_HEADER_SIZE);
    _stream.write(reinterpret_cast<const char*>(bmpInfoHeader.get().data()), BMP_INFO_HEADER_SIZE);
}


void ImageWriter::writePixel(const Color& color)
{
    _stream.write(reinterpret_cast<const char*>(&color), sizeof(uint8_t) * 3);
}


void ImageWriter::writeImageChunk(const ImageChunk* chunk, const Color& baseColor, const Color& complementaryColor)
{
    for (uint32_t i = 0; i < chunk->size(); ++i)
    {
        if (chunk->get(i))
            _stream.write(reinterpret_cast<const char*>(&complementaryColor), sizeof(uint8_t) * 3);
        else
            _stream.write(reinterpret_cast<const char*>(&baseColor), sizeof(uint8_t) * 3);
    }
}
