#ifndef CHUNK_INCLUDED
#define CHUNK_INCLUDED


#include "exception/exception.h"
#include <stdexcept>
#include <mutex>
#include <cstdint>
#include <memory>
#include <vector>


template<typename T>
class Chunk
{
public:
    Chunk();
    ~Chunk();
    void setSize(const uint32_t size);
    void push(const T& value);
    uint32_t size() const;
    std::shared_ptr<T> get(const uint32_t index) const;
    void get(const uint32_t index, T& value) const;
    void set(const uint32_t index, const T& value);
    void reserve(const uint32_t size);
    void clear();
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    Chunk& operator=(const Chunk&) = delete;
    Chunk(const Chunk& chunk);

private:
    uint32_t _size;
    std::vector<T> _chunk;
    //std::mutex _mutex;

};


template<typename T>
Chunk<T>::Chunk() = default;


template<typename T>
Chunk<T>::~Chunk() = default; 


template<typename T>
inline void Chunk<T>::setSize(const uint32_t size)
{
    _size = size;
}


template<typename T>
inline void Chunk<T>::push(const T& value)
{
    _chunk.push_back(value);
}


template<typename T>
inline uint32_t Chunk<T>::size() const
{
    return _size;
}


template<typename T>
std::shared_ptr<T> Chunk<T>::get(const uint32_t index) const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= _size)
        throw RangeException("The index is out of range.");
    const std::shared_ptr<T> value(new T(_chunk[index]));
    return value;
}


template<typename T>
void Chunk<T>::get(const uint32_t index, T& value) const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= _size)
        throw RangeException("The index is out of range.");
    value = _chunk[index];
}


template<typename T>
void Chunk<T>::set(const uint32_t index, const T& value)
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if (index >= _size)
        throw RangeException("The index is out of range.");
    _chunk[index] = value;
}


template<typename T>
inline void Chunk<T>::reserve(const uint32_t size)
{
//  std::lock_guard<std::mutex> lock(_mutex);
    _chunk.reserve(size);
}


template<typename T>
inline void Chunk<T>::clear()
{
//  std::lock_guard<std::mutex> lock(_mutex);
    _chunk.clear();
}


template<typename T>
inline typename std::vector<T>::iterator Chunk<T>::begin()
{
    return _chunk.begin();
}


template<typename T>
inline typename std::vector<T>::iterator Chunk<T>::end()
{
    return _chunk.end();
}


template<typename T>
Chunk<T>::Chunk(const Chunk<T>& source)
{
//  std::lock_guard<std::mutex> lock(source._mutex);
    _chunk = source._chunk;
}


#endif
