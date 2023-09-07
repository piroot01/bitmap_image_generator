#ifndef DRAWABLE_OBJECTS_INCLUDED
#define DRAWABLE_OBJECTS_INCLUDED


#include "algorithms/algorithm.h"
#include "colors/color.h"


/**
* @class DrawableObject
* @brief Base class for all drawable objects
*/
class DrawableObject
{
public:
    /**
    * @brief Constructor
    * @param algorithm shared pointer to an algorithm that will be used to generate the actual object
    * @param color the color of the object
    */
    explicit DrawableObject(const std::shared_ptr<Algorithm> algorithm, const Color& color);

    /**
    * @brief generate
    * @defail Essentially it trigers the algorithm
    * @return void
    */
    virtual void generate() const = 0;

    /**
    * @brief check
    * @defail Used to check the object if it is possible to generate it and display it
    * @param imageWidth
    * @param imageHeight
    * @return void
    */
    virtual void check(const uint32_t imageWidth, const uint32_t imageHeight) const = 0;

protected:
    const std::shared_ptr<Algorithm> _pAlgorithm;
    const Color& _color;

public:
    friend class QueueProcessor;

};


#endif
