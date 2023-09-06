#include "managers/image_task_manager.h"
#include "processors/queue_processor.h"
#include "utils/timer.h"
#include "algorithms/bresenham_normal.h"
#include "image_objects/line.h"
#include "image/image.h"
#include "preparators/image_task_manager_preparator.h"
#include "parameters/manager_task_parameters.h"
#include "thread_pool/thread_pool.h"
#include <iostream>
#include <thread>



int main()
{
    Timer t;
    std::shared_ptr<PointCollection> pPointCollection = std::make_shared<PointCollection>(10);
    std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointCollection);
    DrawableObjectsQueue queue;

    Point start(87, 96);
    Point end(34, 23);
    std::shared_ptr<Line> pLine = std::make_shared<Line>(pAlgorithm, start, end, Colors::green);
    queue.push(pLine);

    start = Point(60, 10);
    end = Point(18, 15);
    std::shared_ptr<Line> pLine1 = std::make_shared<Line>(pAlgorithm, start, end, Colors::red);
    queue.push(pLine1);

    start = Point(50, 30);
    end = Point(70, 15);
    std::shared_ptr<Line> pLine2 = std::make_shared<Line>(pAlgorithm, start, end, Colors::blue);
    queue.push(pLine2);

    PixelSet pixelSet;
    QueueProcessor processor(queue, pPointCollection);
    processor.process(pixelSet);

    Image myImage("out.bmp", 100, 100);
    myImage.generateHeader();

    ImageTaskManager manager(100, myImage, pixelSet);
    manager.setConcurrentThreadNum(4);
    manager.run();

    return 0;
}
