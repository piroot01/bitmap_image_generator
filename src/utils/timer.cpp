#include "utils/timer.h"
#include <iostream>


Timer::Timer()
{
    _start = std::chrono::steady_clock::now();
}


Timer::~Timer()
{
    _end = std::chrono::steady_clock::now();
    std::cout << "Timer: " << std::chrono::duration_cast<std::chrono::microseconds>(_end - _start) << '\n';
}
