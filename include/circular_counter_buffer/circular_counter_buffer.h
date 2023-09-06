#ifndef CIRCULAR_COUNTER_BUFFER_INCLUDED
#define CIRCULAR_COUNTER_BUFFER_INCLUDED


#include <boost/circular_buffer.hpp>


#define DEFAULT_SIZE 16


template<typename T>
class CircularCounterBuffer
{
public:
    explicit CircularCounterBuffer(const size_t size = DEFAULT_SIZE);
    void setCapacity(const size_t capacity);
    void resetCounter();
    uint32_t getCounter() const;
    void push(const T& value);
    void back(T& value);

    typename boost::circular_buffer<T>::const_iterator begin() const;
    typename boost::circular_buffer<T>::const_iterator end() const;
    typename boost::circular_buffer<T>::const_reverse_iterator rbegin() const;

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
    if (_counter >= _buffer.capacity())
        _buffer.set_capacity(2 * _counter);
    _buffer.push_back(value);
    _counter++;
}


template<typename T>
void CircularCounterBuffer<T>::back(T& value)
{
    value = _buffer.back();
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


template<typename T>
inline typename boost::circular_buffer<T>::const_reverse_iterator CircularCounterBuffer<T>::rbegin() const
{
    return _buffer.rbegin();
}


#endif
