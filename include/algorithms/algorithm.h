#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED


#include "parameters/parameters.h"
#include "algorithms/point_collection.h"
#include <memory>


/**
* @class Algorithm
* @brief Base class for algorithms
*/
class Algorithm
{
public:

    /**
    * @brief Default constructor
    * @param pPointCollection shared pointer to PointCollection
    */
    explicit Algorithm(const std::shared_ptr<PointCollection> pPointCollection);

    /**
    * @brief Run virutal method
    * @param parameters raw poiter to Parameters
    * @return void
    */ 
    virtual void run(const Parameters* parameters) = 0;

protected:
    std::shared_ptr<PointCollection> _pPointCollection;

public:
    friend class QueueProcessor;

};


#endif
