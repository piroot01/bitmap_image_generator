#ifndef POINT_INCLUDED
#define POINT_INCLUDED


#include <cstdint>


class Point
{
public:
    Point();
    Point(const uint32_t x, const uint32_t y);
    Point(const Point& point) = default;
    uint32_t getX() const;
    uint32_t getY() const;

private:
    uint32_t _x;
    uint32_t _y;

};


inline uint32_t Point::getX() const
{
    return _x;
}


inline uint32_t Point::getY() const
{
    return _y;
}


#endif
