#ifndef LINE_INCLUDED
#define LINE_INCLUDED

#include "parameters/line_parameters.h"
#include "image_objects/drawable_object.h"
#include "image_objects/point.h"
#include "colors/color.h"
#include "exception/exception.h"


/**
* @clas Line
* @brief DrawableObject
*/
class Line : public DrawableObject
{
public:
    /**
    * @brief Constructor with lvalue points
    * @param algorithm it generates the actual object
    * @param start point
    * @param end point
    * @param color
    */
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const Point& start, const Point& end, const Color& color);

    /**
    * @brief Constructor with rvalue points
    * @param algorithm it generates the actual object
    * @param start point
    * @param end point
    * @param color
    */
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const Point&& start, const Point&& end, const Color& color);

    /**
    * @brief Constructor with LineParameters
    * @param algorithm it generates the actual object
    * @param parameters
    * @param color
    */
    explicit Line(const std::shared_ptr<Algorithm> algorithm, const LineParameters& parameters, const Color& color);

    /**
    * @brief generate
    * @detail implements the base method
    * @retirn void
    */
    void generate() const override;

    /**
    * @brief check
    * @detail implements the base method
    * @param imageWidht
    * @param imageHeight
    * @retirn void
    */
    void check(const uint32_t imageWidth, const uint32_t imageHeight) const override;

private:
    const LineParameters _parameters;

};


inline void Line::generate() const
{
    _pAlgorithm->run(&_parameters);
}


inline void Line::check(const uint32_t imageWidth, const uint32_t imageHeight) const
{
    if (_parameters._start.x >= imageWidth or
        _parameters._start.y >= imageHeight or
        _parameters._end.x >= imageWidth or
        _parameters._end.y >= imageWidth)
        throw InvalidArgumentException("The line endpoints are not within the image boundaries.");
}

#endif
