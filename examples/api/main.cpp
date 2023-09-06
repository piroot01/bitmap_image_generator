#include "api/api.h"
#include "image_objects/line.h"
#include "algorithms/bresenham_normal.h"
#include "utils/timer.h"
#include "colors/colors.h"
#include <iostream>


int main()
{
    Timer t;
    Api myImage("image.bmp", 100, 100);

    std::shared_ptr<PointCollection> pPointCollection = std::make_shared<PointCollection>();
    std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointCollection);
    std::unique_ptr<DrawableObjectsQueue> queue = std::make_unique<DrawableObjectsQueue>();

    std::shared_ptr<Line> pLine1 = std::make_shared<Line>(pAlgorithm, Point(99, 2), Point(20, 20), Colors::red);
    queue->push(pLine1);
    std::shared_ptr<Line> pLine2 = std::make_shared<Line>(pAlgorithm, Point(34, 2), Point(65, 84), Colors::blue);
    queue->push(pLine2);
    std::shared_ptr<Line> pLine3 = std::make_shared<Line>(pAlgorithm, Point(7, 2), Point(56, 20), Colors::green);
    queue->push(pLine3);
    std::shared_ptr<Line> pLine4 = std::make_shared<Line>(pAlgorithm, Point(8, 34), Point(20, 87), Colors::black);
    queue->push(pLine4);

    try
    {
        myImage.process(queue.get());
    }
    catch (Exception& exception)
    {
        std::cout << exception.displayText() << '\n';
    }

    return 0;
}
