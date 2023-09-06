#ifndef MANAGER_TASK_PARAMETERS_INCLUDED
#define MANAGER_TASK_PARAMETERS_INCLUDED


#include "parameters/parameters.h"
#include "parameters/image_task_manager_preparator_parameters.h"
#include "image_objects/pixel_set.h"
#include "image/image.h"
#include <vector>


class ManagerTaskParameters : public Parameters
{
public:
    explicit ManagerTaskParameters(const IdSizeIterator& iterator, const ImageTaskManagerPreparatorParameters& parameters, const Image* pImage);

public:
    IdSizeIterator _iterator;
    const ImageTaskManagerPreparatorParameters* _parameters;
    const Image* _pImage;

public:
    friend class ManagerTask;

};


#endif
