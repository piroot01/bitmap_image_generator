#ifndef POINT_INCLUDED
#define POINT_INCLUDED


#include <cstdint>


class Point
{
public:
    Point();
    Point(const uint32_t x, const uint32_t y);
    Point(const Point& point) = default;
    Point& operator=(const Point& source) = default;

public:
    uint32_t x;
    uint32_t y;

};


inline bool operator<(const Point& lhs, const Point& rhs)
{
    return (lhs.x + lhs.y) < (rhs.x + rhs.y);
}


#endif
