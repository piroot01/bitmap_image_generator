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
        Point start(11, 13);
        Point end(42, 42);
        std::shared_ptr<PointSet> pPointSet = std::make_shared<PointSet>();
        std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointSet);
        Line line(pAlgorithm, start, end, Colors::black);
        line.generate();

        int i = 0;
        for (const Point& point : *pPointSet)
            std::cout << "[" << i++ << "]: " << point.x << ", " << point.y << '\n';
    }
    return 0;
}
