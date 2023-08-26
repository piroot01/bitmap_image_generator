#include "algorithms/bresenham_normal.h"
#include <cmath>
#include <cstdint>


void BresenhamNormal::run(const Point& start, const Point& end)
{
    int32_t lx = end.x - start.x;
    int32_t ly = end.y - start.y;

    int32_t dx = abs(lx);
    int32_t dy = -abs(ly);

    int32_t sx = (start.x < end.x) ? 1 : -1;
    int32_t sy = (start.y < end.y) ? 1 : -1;

    int32_t error = dx + dy;

    Point p(start.x, start.y);

    while(true)
    {
        _pPointSet->emplace(p);
        if(start.x == end.x and start.y == end.y)
            break;
        int32_t error2 = 2 * error;
        if(error2 >= dy)
        {
            if(p.x == end.x)
                break;
            error += dy;
            p.x += sx;
        }
        if(error2 <= dx)
        {
            if(p.y == end.y)
                break;
            error += dx;
            p.y += sy;
        }
    }
}
