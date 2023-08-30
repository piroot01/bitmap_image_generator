#include "processors/point_set_processor.h"
#include "processors/queue_processor.h"
#include "image_objects/line.h"
#include "image_objects/point_set.h"
#include "image_objects/drawable_objects_queue.h"
#include "algorithms/bresenham_normal.h"
#include "utils/timer.h"
#include <memory>
#include <iostream>


int main()
{
    Timer t;
    std::shared_ptr<PointCollection> pPointCollection = std::make_shared<PointCollection>(15);
    std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointCollection);
    DrawableObjectsQueue queue;

    // Bunch of lines
    Point start(0, 0);
    Point end(10, 10);
    std::shared_ptr<Line> pLine1 = std::make_shared<Line>(pAlgorithm, start, end, Colors::black);
    queue.push(pLine1);

    start.set(0, 0);
    end.set(40, 23);
    std::shared_ptr<Line> pLine2 = std::make_shared<Line>(pAlgorithm, start, end, Colors::black);
    queue.push(pLine2);

    start.set(30, 0);
    end.set(5, 0);
    std::shared_ptr<Line> pLine3 = std::make_shared<Line>(pAlgorithm, start, end, Colors::black);
    queue.push(pLine3);

    PixelSet pixelSet;
    QueueProcessor processor(queue, pPointCollection);
    processor.process(pixelSet);


    int i = 0;
    for (const auto& p : pixelSet)
    {
        assert(p.getColor() == Colors::black);
        std::cout << "[" << i++ << "]: " << p.getPoint().y << ", " << p.getPoint().x << '\n';
    }

    return 0;
}
