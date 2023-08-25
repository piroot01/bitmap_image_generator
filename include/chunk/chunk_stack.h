#define CHUNK_STACK_INCLUDED
#ifdef CHUNK_STACK_INCLUDED


#include "exception/exception.h"
#include <stdexcept>
#include <mutex>
#include <cstdint>
#include <memory>
#include <stack>


template<typename T, uint32_t SIZE>
class ChunkStack
{
public:
    ChunkStack();
    ~ChunkStack() = default;
    void push(const T& value);
    std::shared_ptr<T> top() const;
    void top(T& value) const;
    void clear();
    ChunkStack& operator=(const ChunkStack&) = delete;
    ChunkStack(const ChunkStack& chunk);

private:
    std::stack<T> _stack;
    uint32_t _size;
    //std::mutex _mutex;

};


template<typename T, uint32_t SIZE>
ChunkStack<T, SIZE>::ChunkStack() :
    _size(0)
{
}


template<typename T, uint32_t SIZE>
void ChunkStack<T, SIZE>::push(const T& value)
{
//  std::lock_guard<std::mutex> lock(_mutex);
    if(_size < SIZE)
    {
        _stack.push(value);
        _size++;
    } 
    else
    {
        throw RangeException("The chunk is full.");
    }
}


template<typename T, uint32_t SIZE>
std::shared_ptr<T> ChunkStack<T, SIZE>::top() const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    const std::shared_ptr<T> value(new T(_stack.top()));
    return value;
}


template<typename T, uint32_t SIZE>
void ChunkStack<T, SIZE>::top(T& value) const
{
//  std::lock_guard<std::mutex> lock(_mutex);
    value = _stack.top();
}


template<typename T, uint32_t SIZE>
void ChunkStack<T, SIZE>::clear()
{
//  std::lock_guard<std::mutex> lock(_mutex);
    _stack = std::stack<T>();
    _size = 0;

}

template<typename T, uint32_t SIZE>
ChunkStack<T, SIZE>::ChunkStack(const ChunkStack<T, SIZE>& source)
{
//  std::lock_guard<std::mutex> lock(source._mutex);
    _stack = source._stack;
    _size = source._size;
}


#endif
