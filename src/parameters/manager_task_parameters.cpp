#include "parameters/manager_task_parameters.h"


ManagerTaskParameters::ManagerTaskParameters(const IdSizeIterator& iterator, const ImageTaskManagerPreparatorParameters& parameters, const Image* pImage) :
    _iterator(iterator), _parameters(&parameters), _pImage(pImage)
{
}
