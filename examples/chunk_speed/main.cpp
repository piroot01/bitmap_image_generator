//#include "chunk/chunk.h"
#include "chunk/chunk_stack.h"
#include "utils/timer.h"
#include <array>
#include <vector>


int main()
{
    {
        Timer t1;
        Chunk<std::string, 1000000> chunk;

        for(int i = 0; i < 1000000; ++i)
            chunk.set(i, "hello world");
    }
    {
        Timer t2;
        std::vector<std::string> array;
        array.resize(1000000);

        for(int i = 0; i < 1000000; ++i)
            array[i] = "hello world";
    }
    return 0;
}
