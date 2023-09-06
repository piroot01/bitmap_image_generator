#include "chunk/chunk.h"
#include <iostream>


int main()
{
    Chunk<int> chunk;

    try
    {
        for(uint32_t i = 0; i < 10; ++i)
            chunk.push(i);
    }
    catch(Exception& exception)
    {
        std::cout << exception.displayText() << '\n';
    }
    

    return 0;
}
