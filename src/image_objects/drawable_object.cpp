#include "image_objects/drawable_object.h"


DrawableObject::DrawableObject(const std::shared_ptr<Algorithm> pAlgorithm, const Color& color) :
    _pAlgorithm(pAlgorithm), _color(color)
{
}
