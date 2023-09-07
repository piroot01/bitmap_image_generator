#ifndef CIRCULAR_COUNTER_BUFFER_INCLUDED
#define CIRCULAR_COUNTER_BUFFER_INCLUDED


#include <boost/circular_buffer.hpp>


#define DEFAULT_SIZE 16


/**
* @class CircularCounterBuffer
* @brief Class that implemets circular buffer with active counting
*/
template<typename T>
class CircularCounterBuffer
{
public:

    /**
    * @brief Default constructor
    * @param size
    */
    explicit CircularCounterBuffer(const size_t size = DEFAULT_SIZE);

    /**
    * @brief setCapacity
    * @param capacity
    * @return void
    */
    void setCapacity(const size_t capacity);

    /**
    * @brief resetCounter sets the internal counter to 0
    * @return void
    */
    void resetCounter();
    
    /**
    * @brief getCounter uset to obtain counter value
    * @return uint32_t
    */
    uint32_t getCounter() const;

    /**
    * @brief push pushes new value into the buffer
    * @return uint32_t
    */
    void push(const T& value);

    /**
    * @brief back saves the most recent value into the value
    * @param value
    * @return uint32_t
    */
    void back(T& value);

    /**
    * @brief begin
    * @return const_iterator
    */
    typename boost::circular_buffer<T>::const_iterator begin() const;

    /**
    * @brief end
    * @return const_iterator
    */
    typename boost::circular_buffer<T>::const_iterator end() const;

    /**
    * @brief rbegin
    * @return const_reverse_iterator
    */
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
