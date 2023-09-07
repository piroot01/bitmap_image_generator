#ifndef BASE_WRITER_INCLUDED
#define BASE_WRITER_INCLUDED


#include <fstream>


/**
* @class BaseWriter
* @brief Base class that provides an interface for wrinting into a file
*/
class BaseWriter
{
public:

    /**
    * @rief Default constructor
    */
    BaseWriter();

    /**
    * @brief Constructor
    * @param streamName
    */
    BaseWriter(const std::string& streamName);

    /**
    * @brief setStreamName
    * param streamName
    * return void
    */
    inline void setStreamName(const std::string& stringName);

    /**
    * @brief open
    * @return void
    */
    virtual void open();

    /**
    * @brief close
    * @return void
    */
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
