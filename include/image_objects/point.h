#ifndef POINT_INCLUDED
#define POINT_INCLUDED


#include <cstdint>


class Point
{
public:
    Point();
    Point(const uint32_t x, const uint32_t y);
    Point(const Point& point) = default;

public:
    uint32_t x;
    uint32_t y;

};


#endif
