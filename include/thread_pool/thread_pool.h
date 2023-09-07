#ifndef THREAD_POOL_INCLUDED
#define THREAD_POOL_INCLUDED


#include "thread_safe_queue.h"
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdint>
#include <functional>


/**
* @class ProcessingStrategy
* @brief Used in Thread pool to determine from which end of the queue the tasks will be processed
*/
enum class ProcessingStrategy
{
    POP_BACK,
    POP_FRONT,
};


/**
* @class ThreadPool
* @brief Used to compute queue of task in concurrent manner
* @detail it has STRATEGY template to determine the processing direction
*/
template<ProcessingStrategy STRATEGY = ProcessingStrategy::POP_BACK>
class ThreadPool
{
public:

    /**
    * @brief Constructor
    * @param threadCount if not set the hardware_concurrency will be used
    */
    explicit ThreadPool(const uint32_t threadCount = 0);

    /**
    * @brief Copy constructor is deleted
    */
    ThreadPool(const ThreadPool& other) = delete;

    /**
    * @brief Move constructor is deleted
    */
    ThreadPool(const ThreadPool&& other) = delete;

    /**
    * @brief Copy assign constructor is deleted
    */
    ThreadPool& operator=(const ThreadPool& other) = delete;

    /**
    * @brief Move assign constructor is deleted
    */
    ThreadPool& operator=(const ThreadPool&& other) = delete;

    /**
    * @brief Destructor
    * @detail if the threadPool is not shut down it will be in the time of destruction
    */
    ~ThreadPool();

    /**
    * @brief init starts the processing of the queue
    * @return void
    */
    void init();

    /**
    * @brief shutdown it joins all threads 
    * @return void
    */
    void shutdown();

    /**
    * @brief enqueue
    * @param f is functor
    * @param args list or functor arguments
    * @return std::future
    */
    template<typename F, typename... Args> requires std::invocable<F, Args...>
    [[nodiscard]] auto enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F&&, Args&&...>>;

private:
    void joinAll();

private:
    ThreadSafeQueue<std::function<void()>> _taskQueue;
    std::atomic<bool> _shutdown;
    mutable std::mutex _mutex;
    std::condition_variable _signal;
    std::vector<std::thread> _threads;
    uint32_t _threadCount;

    class ThreadWorker
    {
    public:
        explicit ThreadWorker(ThreadPool* threadPool, const uint32_t id);

        void operator()(); 

    private:
        ThreadPool* _threadPool;
        uint32_t _id;

    };

};


template<ProcessingStrategy STRATEGY>
ThreadPool<STRATEGY>::ThreadPool(const uint32_t threadCount) :
    _shutdown(false)
{
    if (threadCount <= 0)
        _threadCount = std::thread::hardware_concurrency();
    else
        _threadCount = std::min(threadCount, std::thread::hardware_concurrency());
}


template<ProcessingStrategy STRATEGY>
ThreadPool<STRATEGY>::~ThreadPool()
{
    if (!_shutdown)
        shutdown();
}


template<ProcessingStrategy STRATEGY>
void ThreadPool<STRATEGY>::init()
{
    _threads.reserve(_threadCount);
    for (uint32_t i = 0; i < _threadCount; ++i)
        _threads.emplace_back(ThreadWorker(this, i));
}


template<ProcessingStrategy STRATEGY>
void ThreadPool<STRATEGY>::shutdown()
{
    _shutdown = true;
    _signal.notify_all();
    joinAll();
}


template<ProcessingStrategy STRATEGY>
void ThreadPool<STRATEGY>::joinAll()
{
    decltype(_threads) localThreads;
    {
        std::scoped_lock<std::mutex> lock(_mutex);
        localThreads = std::move(_threads);
    }
    for (auto& thread : localThreads)
        thread.join();
}


template<ProcessingStrategy STRATEGY>
ThreadPool<STRATEGY>::ThreadWorker::ThreadWorker(ThreadPool* threadPool, const uint32_t id) :
    _threadPool(threadPool), _id(id)
{
}


template<ProcessingStrategy STRATEGY>
void ThreadPool<STRATEGY>::ThreadWorker::operator()()
{
    auto taskCall = [&]()
    {
        if constexpr (STRATEGY == ProcessingStrategy::POP_BACK)
            return _threadPool->_taskQueue.popBack();
        else
            return _threadPool->_taskQueue.popFront();
    };
    while (!_threadPool->_shutdown)
    {
        std::unique_lock<std::mutex> lock(_threadPool->_mutex);
        if (_threadPool->_taskQueue.empty())
        {
            _threadPool->_signal.wait(lock);
        }
        else
        {
            lock.unlock();
            if (auto task = taskCall())
                std::invoke(std::move(task.value()));
        }
    }
}


template<ProcessingStrategy STRATEGY>
template<typename F, typename... Args> requires std::invocable<F, Args...>
[[nodiscard]] auto ThreadPool<STRATEGY>::enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F&&, Args&&...>>
{
    using ReturnType = std::invoke_result_t<F&&, Args&&...>;
    auto sharedPromise = std::make_shared<std::promise<ReturnType>>();
    auto future = sharedPromise->get_future();
    auto task = [func = std::move(f), ... largs = std::move(args), promise = sharedPromise]
    {
        try
        {
            if constexpr (std::is_same_v<ReturnType, void>)
            {
                func(largs...);
                promise->set_value();
            }
            else
            {
                promise->set_value(func(largs...));
            }
        }
        catch (...)
        {
            promise->set_exception(std::current_exception());
        }
    };
    _taskQueue.pushBack(std::move(task));
    _signal.notify_one();
    return future;
}


#endif
