#define CHUNK_INCLUDED
#ifdef CHUNK_INCLUDED


#include "exception/exception.h"
#include <stdexcept>
#include <mutex>
#include <cstdint>


template<typename T, uint32_t SIZE>
class Chunk
{
public:
    Chunk();
    ~Chunk();
    void insert(const T& value);
    T at(const uint32_t position) const;
    void clear();
    Chunk& operator=(const Chunk&) = delete;
    Chunk(const Chunk& chunk);

private:
    T* _chunk;
    T* _last_inserted;
    uint32_t _size;
    std::mutex _mutex;

};


template<typename T, uint32_t SIZE>
Chunk<T, SIZE>::Chunk() :
    _size(0)
{
    _chunk = new T[SIZE];
    _last_inserted = _chunk;
}


template<typename T, uint32_t SIZE>
Chunk<T, SIZE>::~Chunk()
{
    delete[] _chunk;
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::insert(const T& value)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if(_size < SIZE)
    {
        *(_last_inserted++) = value;
        _size++;
    } 
    else
    {
        throw RangeException("The chunk is full.");
    }
}


template<typename T, uint32_t SIZE>
T Chunk<T, SIZE>::at(const uint32_t index) const
{
    if (index >= SIZE)
        throw RangeException("The index is out of range.");
    return _chunk[index];;
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::clear()
{
    std::lock_guard<std::mutex> lock(_mutex);
    _last_inserted = _chunk;
    _size = 0;

}

template<typename T, uint32_t SIZE>
Chunk<T, SIZE>::Chunk(const Chunk<T, SIZE>& source)
{
    std::lock_guard<std::mutex> lock(source._mutex);
    _chunk = new T[SIZE];
    memcpy(_chunk, source._chunk, SIZE * sizeof(T));
    _last_inserted = _chunk + (source._last_inserted - source._chunk);
    _size = source._size;
}


#endif
