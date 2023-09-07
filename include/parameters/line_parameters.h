#ifndef LINE_PARAMETERS_INCLUDED
#define LINE_PARAMETERS_INCLUDED


#include "parameters/parameters.h"
#include "image_objects/point.h"


/**
* @class LineParameters
* @brief Holds the parameters that are essential for line algorithms
*/
class LineParameters : public Parameters
{
public:
    /**
    * @brief Constructor
    * @param start
    * @param end
    */
    explicit LineParameters(const Point& start, const Point& end);

protected:
    const Point _start;
    const Point _end;

public:
    friend class LineAlgorithm;
    friend class Line;

};


#endif
