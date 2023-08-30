#include "image_objects/line.h"
#include "image_objects/point_set.h"
#include "algorithms/bresenham_normal.h"
#include "utils/timer.h"
#include <memory>
#include <iostream>


int main()
{
    {
        Timer t;
        Point start(0, 0);
        Point end(50, 50);
        std::shared_ptr<PointCollection> pPointCollection = std::make_shared<PointCollection>(50);
        std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointCollection);
        Line line(pAlgorithm, start, end, Colors::black);
        line.generate();

        std::cout << "Counter: " << pPointCollection->getCounter() << ", number of elements: " << pPointCollection->_buffer.size() << '\n';
        
        int i = 0;
        for (const Point& point : *pPointCollection)
            std::cout << "[" << i++ << "]: " << point.x << ", " << point.y << '\n';

    }
    return 0;
}
