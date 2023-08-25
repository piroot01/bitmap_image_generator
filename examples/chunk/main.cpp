#include "chunk/chunk.h"
#include <iostream>


int main()
{
    Chunk<int, 10> chunk;

    try
    {
        for(uint32_t i = 0; i < 10; ++i)
            chunk.insert(i);

        for(uint32_t i = 0; i < 10; ++i)
            std::cout << chunk.at(i) << '\n';
    }
    catch(Exception& exception)
    {
        std::cout << exception.displayText() << '\n';
    }
    

    return 0;
}
