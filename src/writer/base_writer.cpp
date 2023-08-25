#include "writer/base_writer.h"


BaseWriter::BaseWriter() = default;


BaseWriter::~BaseWriter()
{
}


BaseWriter::BaseWriter(const std::string& streamName) :
    _streamName(streamName)
{
}


void BaseWriter::open()
{
    _stream.open(_streamName);
}
