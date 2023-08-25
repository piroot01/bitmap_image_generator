#ifndef CHUNK_INCLUDED
#define CHUNK_INCLUDED


#include "exception/exception.h"
#include <stdexcept>
#include <mutex>
#include <cstdint>
#include <memory>


template<typename T, uint32_t SIZE>
class Chunk
{
public:
    Chunk();
    ~Chunk() = default;
    void insert(const T& value);
    std::shared_ptr<T> get(const uint32_t index) const;
    void get(const uint32_t index, T& value) const;
    void set(const uint32_t index, const T& value);
    void clear();
    Chunk& operator=(const Chunk&) = delete;
    Chunk(const Chunk& chunk);

private:
    std::unique_ptr<T[]> _chunk;
    T* _last_inserted;
    uint32_t _size;
    //std::mutex _mutex;

};


template<typename T, uint32_t SIZE>
Chunk<T, SIZE>::Chunk() :
    _chunk(std::make_unique<T[]>(SIZE)),
    _last_inserted(_chunk.get()),
    _size(0)
{
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::insert(const T& value)
{
//  std::lock_guard<std::mutex> lock(_mutex);
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
std::shared_ptr<T> Chunk<T, SIZE>::get(const uint32_t index) const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= SIZE)
        throw RangeException("The index is out of range.");
    const std::shared_ptr<T> value(new T(_chunk[index]));
    return value;
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::get(const uint32_t index, T& value) const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= SIZE)
        throw RangeException("The index is out of range.");
    value = _chunk[index];
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::set(const uint32_t index, const T& value)
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= SIZE)
        throw RangeException("The index is out of range.");
    _chunk[index] = value;
}


template<typename T, uint32_t SIZE>
void Chunk<T, SIZE>::clear()
{
//  std::lock_guard<std::mutex> lock(_mutex);
    _last_inserted = _chunk;
    _size = 0;

}

template<typename T, uint32_t SIZE>
Chunk<T, SIZE>::Chunk(const Chunk<T, SIZE>& source)
{
//  std::lock_guard<std::mutex> lock(source._mutex);
    _chunk = new T[SIZE];
    memcpy(_chunk, source._chunk, SIZE * sizeof(T));
    _last_inserted = _chunk + (source._last_inserted - source._chunk);
    _size = source._size;
}


#endif
