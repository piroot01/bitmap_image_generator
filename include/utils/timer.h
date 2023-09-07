#ifndef TIMER_INCLUDED
#define TIMER_INCLUDED


#include <chrono>


/**
* @class Timer
* @brief it uses RAII style timing
*/
class Timer
{
public:

    /**
    * @brief Constructor
    * @detail It starts the steady_clock
    */
    Timer();

    /**
    * @brief Destructor
    * @detail It stops the steady_clock and prints the diff
    */
    ~Timer();

private:
    std::chrono::time_point<std::chrono::steady_clock> _start;
    std::chrono::time_point<std::chrono::steady_clock> _end;

};


#endif
