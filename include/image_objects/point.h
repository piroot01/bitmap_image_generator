#ifndef POINT_INCLUDED
#define POINT_INCLUDED


#include <cstdint>


/**
* @class Point
* @brief Publicly stores two points
*/
class Point
{
public:
    /**
    * @brief Default Constructor
    */
    Point();

    /**
    * @brief Contructor
    * @param x
    * @param y
    */
    Point(const uint32_t x, const uint32_t y);

    /**
    * @brief set
    * @param x
    * @param y
    */
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
