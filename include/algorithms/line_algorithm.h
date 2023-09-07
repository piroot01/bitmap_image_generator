#ifndef BRESENHAM_INCLUDED
#define BRESENHAM_INCLUDED


#include "parameters/line_parameters.h"
#include "algorithms/algorithm.h"
#include "algorithms/point_collection.h"
#include "colors/color.h"
#include <memory>


/**
* @class LineAlgorithm
* @brief Derived class from Algorithm
*/
class LineAlgorithm : public Algorithm
{
public:

    /**
    * @brief Default constructor
    * @param pPointCollection shared pointer to PointCollection
    */
    explicit LineAlgorithm(const std::shared_ptr<PointCollection> pPointCollection);

    /**
    * @brief Run virtual method
    * @param parameters raw poiter to Parameters
    * @return void
    */
    virtual void run(const Parameters* pParameters) = 0;


};


#endif
