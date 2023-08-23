#define BASE_WRITER_INCLUDED
#ifdef BASE_WRITER_INCLUDED


#include <fstream>


class BaseWriter
{
public:
    BaseWriter();
    BaseWriter(const std::string& streamName);
    BaseWriter(const std::string&& streamName);
    inline void setStreamName(const std::string& stringName);
    virtual void open();
//    virtual void writeByte(const char byte);
//    virtual void writeChunk(const std::string& data);
    inline void close();

protected:
    virtual ~BaseWriter();
    std::ofstream _stream;
    std::string _streamName;

};


inline void BaseWriter::setStreamName(const std::string& streamName)
{
    _streamName = streamName;
}


inline void BaseWriter::close()
{
    _stream.close();
}


#endif
