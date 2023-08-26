#include "image_objects/drawable_object.h"


DrawableObject::DrawableObject() :
    _pAlgorithm(nullptr)
{
}

DrawableObject::DrawableObject(std::shared_ptr<Algorithm> pAlgorithm) :
    _pAlgorithm(pAlgorithm)
{
}
