#include "circular_counter_buffer/circular_counter_buffer.h"
#include <iostream>

int main()
{
    CircularCounterBuffer<int> cb(2);

    for (int i = 0; i < 12; ++i)
        cb.push(i);

    std::cout << cb.getCounter() << '\n';

    for (const auto& i : cb)
        std::cout << i << '\n';

    return 0;
}
