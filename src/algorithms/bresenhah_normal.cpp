#include "algorithms/bresenham_normal.h"
#include "algorithms/bresenham_normal_parameters.h"
#include "exception/exception.h"
#include <cmath>
#include <cstdint>
#include <iostream>


BresenhamNormal::BresenhamNormal(const std::shared_ptr<PointSet> pPointSet) :
    LineAlgorithm(pPointSet)
{
}


void BresenhamNormal::run(const Parameters* pParameters)
{
    const BresenhamNormalParameters* pBresenhamParameters = static_cast<const BresenhamNormalParameters*>(pParameters);

    if (pBresenhamParameters == nullptr)
        throw BadCastException();

    Point p(pBresenhamParameters->_start);

    int32_t w = pBresenhamParameters->_end.x - pBresenhamParameters->_start.x;
    int32_t h = pBresenhamParameters->_end.y - pBresenhamParameters->_start.y;

    int32_t dx1 = 0;
    int32_t dx2 = 0;
    int32_t dy1 = 0;
    int32_t dy2 = 0;

    if (w < 0)
    {
        dx1 = -1;
        dx2 = -1;
    }
    else if (w > 0)
    {
        dx1 = 1;
        dx2 = 1; 
    }

    if (h < 0)
        dy1 = -1;
    else if (h > 0)
        dy1 = 1;

    int32_t longest = abs(w);
    int32_t shortest = abs(h);

    if (longest <= shortest)
    {
        longest = abs(h);
        shortest = abs(w);
        if (h < 0)
            dy2 = -1;
        else if (h > 0)
            dy2 = 1;
        dx2 = 0;
    }

    int numerator = longest >> 1;

    for (int32_t i = 0; i <= longest; ++i)
    {
        _pPointSet->emplace(p);
        numerator += shortest;
        if (numerator >= longest)
        {
            numerator -= longest;
            p.x += dx1;
            p.y += dy1;
        }
        else
        {
            p.x += dx2;
            p.y += dy2;
        }
    }
}
