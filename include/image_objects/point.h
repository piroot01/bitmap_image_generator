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

    void set(const uint32_t x, const uint32_t y);

public:
    uint32_t x;
    uint32_t y;

};


inline bool operator<(const Point& lhs, const Point& rhs)
{
    return (lhs.y < rhs.y) || (lhs.y == rhs.y && lhs.x < rhs.x);
}


inline void Point::set(const uint32_t x, const uint32_t y)
{
    this->x = x;
    this->y = y;
}


#endif
