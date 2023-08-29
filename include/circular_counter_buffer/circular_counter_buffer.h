#ifndef CIRCULAR_COUNTER_BUFFER_INCLUDED
#define CIRCULAR_COUNTER_BUFFER_INCLUDED


#include <boost/circular_buffer.hpp>


template<typename T>
class CircularCounterBuffer
{
public:
    explicit CircularCounterBuffer(const size_t size);
    void setCapacity(const size_t capacity);
    void resetCounter();
    uint32_t getCounter() const;
    void push(const T& value);
    void pop(T& value);
    typename boost::circular_buffer<T>::const_iterator begin() const;
    typename boost::circular_buffer<T>::const_iterator end() const;

private:
    boost::circular_buffer<T> _buffer;
    uint32_t _counter;

};


template<typename T>
CircularCounterBuffer<T>::CircularCounterBuffer(const size_t size) :
    _buffer(size), _counter(0)
{
}


template<typename T>
inline void CircularCounterBuffer<T>::setCapacity(const size_t newCapacity)
{
    _buffer.set_capacity(newCapacity);
}


template<typename T>
inline void CircularCounterBuffer<T>::resetCounter()
{
    _counter = 0;
}


template<typename T>
void CircularCounterBuffer<T>::push(const T& value)
{
    if (_counter >= _buffer.size())
        _buffer.set_capacity(2 * _counter);
    _counter++;
    _buffer.push_back(value);
}


template<typename T>
void CircularCounterBuffer<T>::pop(T& value)
{
    value = _buffer.back();
    _buffer.pop_back();
}


template<typename T>
inline uint32_t CircularCounterBuffer<T>::getCounter() const
{
    return _counter;
}


template<typename T>
inline typename boost::circular_buffer<T>::const_iterator CircularCounterBuffer<T>::begin() const
{
    return _buffer.begin();
}


template<typename T>
inline typename boost::circular_buffer<T>::const_iterator CircularCounterBuffer<T>::end() const
{
    return _buffer.end();
}


#endif
