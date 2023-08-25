#define TIMER_INCLUDED
#ifdef TIMER_INCLUDED


#include <chrono>


class Timer
{
public:
    Timer();
    ~Timer();
    Timer& operator=(const Timer& timer);

private:
    std::chrono::time_point<std::chrono::steady_clock> _start;
    std::chrono::time_point<std::chrono::steady_clock> _end;

};

#endif
