#include "chunk/chunk.h"
#include "chunk/chunk_stack.h"
#include "utils/timer.h"
#include <array>
#include <vector>


int main()
{
    Chunk<std::string, 1000000> chunk;
    {
        Timer t1;

        for(int i = 0; i < 1000000; ++i)
            chunk.push("hello world");
    }
    return 0;
}
