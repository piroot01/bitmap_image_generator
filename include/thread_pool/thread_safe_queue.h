#ifndef THREAD_SAFE_QUEUE_INCLUDED
#define THREAD_SAFE_QUEUE_INCLUDED


#include <deque>
#include <mutex>
#include <optional>


/**
* @class ThreadSafeQueue
* @brief Essentially a queue that is possible to acces with multiple consurrent threads
* @detail It require the data typename and the mutex type is optional (default is std::mutex)
*/
template<typename T, typename Lock = std::mutex>
class ThreadSafeQueue
{
public:

    /**
    * @cbrief Default constructor
    */
    ThreadSafeQueue() = default;

    /**
    * @cbrief Copy constructor is deleted
    */
    ThreadSafeQueue(const ThreadSafeQueue& other) = delete;

    /**
    * @cbrief Copy assign constructor is deleted
    */
    ThreadSafeQueue& operator=(const ThreadSafeQueue& other) = delete;

    /**
    * @cbrief Move constructor
    * @detail The mutex is not moved
    */
    ThreadSafeQueue(const ThreadSafeQueue&& other);

    /**
    * @cbrief Move assign constructor
    * @detail The mutex is not moved
    */
    ThreadSafeQueue& operator=(const ThreadSafeQueue&& other);

    /**
    * @brief Default destructor
    */
    virtual ~ThreadSafeQueue() = default;

    /**
    * @cbrief pushBack
    * @param value is rvalue
    */
    void pushBack(T&& value);

    /**
    * @cbrief pushFront
    * @param value is rvalue
    */
    void pushFront(T&& value);

    /**
    * @cbrief empty
    * @return bool if the queue is empty than it is true
    */
    [[nodiscard]] bool empty() const;

    /**
    * @cbrief popBack
    * @return std::optional<T> if other thread steals the item from queue and the queue is empty then the optional is nullopt
    */
    [[nodiscard]] std::optional<T> popBack();

    /**
    * @cbrief popFront
    * @return std::optional<T> if other thread steals the item from queue and the queue is empty then the optional is nullopt
    */
    [[nodiscard]] std::optional<T> popFront();

private:
    std::deque<T> _data;
    mutable Lock _mutex;

};


template<typename T, typename Lock>
ThreadSafeQueue<T, Lock>::ThreadSafeQueue(const ThreadSafeQueue<T, Lock>&& other)
{
    std::scoped_lock<Lock> lock(_mutex);
    _data = std::move(other._data);
}


template<typename T, typename Lock>
ThreadSafeQueue<T, Lock>& ThreadSafeQueue<T, Lock>::operator=(const ThreadSafeQueue<T, Lock>&& other)
{
    if (this != &other)
    {
        std::unique_lock<std::mutex> lhsLock(_mutex, std::defer_lock);
        std::unique_lock<std::mutex> rhsLock(other._mutex, std::defer_lock);
        std::lock(lhsLock, rhsLock);
        _data = std::move(other._data);
    }
    return *this;
}


template<typename T, typename Lock>
void ThreadSafeQueue<T, Lock>::pushBack(T&& value)
{
    std::scoped_lock<Lock> lock(_mutex);
    _data.push_back(std::forward<T>(value));
}


template<typename T, typename Lock>
void ThreadSafeQueue<T, Lock>::pushFront(T&& value)
{
    std::scoped_lock<Lock> lock(_mutex);
    _data.push_front(std::forward<T>(value));
}


template<typename T, typename Lock>
[[nodiscard]] bool ThreadSafeQueue<T, Lock>::empty() const
{
    std::scoped_lock<Lock> lock(_mutex);
    return _data.empty();
}


template<typename T, typename Lock>
[[nodiscard]] std::optional<T> ThreadSafeQueue<T, Lock>::popFront()
{
    std::scoped_lock<Lock> lock(_mutex);
    if (_data.empty())
        return std::nullopt;
    auto front = std::move(_data.front());
    _data.pop_front();
    return front;
}


template<typename T, typename Lock>
[[nodiscard]] std::optional<T> ThreadSafeQueue<T, Lock>::popBack()
{
    std::scoped_lock<Lock> lock(_mutex);
    if (_data.empty())
        return std::nullopt;
    auto front = std::move(_data.back());
    _data.pop_back();
    return front;
}


#endif
