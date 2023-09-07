#ifndef BRESENHAM_NORMAL_INCLUDED
#define BRESENHAM_NORMAL_INCLUDED


#include "algorithms/line_algorithm.h"


/**
* @class Algorithm
* @brief Base class for algorithms
*/
class BresenhamNormal : public LineAlgorithm
{
public:

    /**
    * @brief Default constructor
    * @param pPointCollection shared pointer to PointCollection
    */
    explicit BresenhamNormal(const std::shared_ptr<PointCollection> pPointCollection);

   /**
    * @brief Run virutal method
    * @param parameters raw poiter to Parameters
    * @detail It implements basic Bresenham algorithm
    * @return void
    */ 
    void run(const Parameters* pParameters);

};


#endif
