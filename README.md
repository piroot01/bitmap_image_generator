# Bitmap Image Generator

Bitmap Image Generator is a C++ program that allows you to create bitmap images by drawing simple lines from one point to another. It supports various features and is designed for ease of use and extensibility.

## Features

1. **Simple Line Drawing:** This program currently implements simple line drawing, allowing you to create lines from one point to another.

2. **Image Generation:** You can generate bitmap images on multiple threads.

4. **CMake Build:** The program is compiled and built using CMake, making it easy to build on different platforms.

## Documentation

The documentation for this project is generated using Doxygen. You can generate the documentation by running the following command:

    doxygen config

The documentation will be generated inside the 'doc' directory.

## Customization

 - Line Color: You can specify the color of lines, and the program supports any 255-255-255 color.
 - Extensible: The program is designed to be extensible and ready for various drawable objects such as circles, ovals, curves, and more. It also supports different algorithm implementations for each object for experimental purposes.
 - Custom Exception Class: The program includes a custom exception class for handling errors and exceptions.

## Limits

 - Color choice, easy to extend :d
 - Max image resolution of 4294967295 pixels

## To-Do List

 - [ ] Support for more drawable objects, such as circles, ovals, and curves.
 - [ ] Multithread the execution of drawable objects for improved performance. Note that with the current implementation, multithreading is not reasonable.

## Getting Started

To get started with Bitmap Image Generator, clone the repository and build it with CMake.

## Example Usage

Here's an example of how to use the Bitmap Image Generator in your C++ code:

```cpp
#include "api/api.h"
#include "image_objects/line.h"
#include "algorithms/bresenham_normal.h"
#include "utils/timer.h"
#include "colors/colors.h"
#include <iostream>

int main()
{
    // Time the whole program
    Timer t;

    // Create image
    Api myImage("image.bmp", 100, 100);

    // Storege for algorithms
    std::shared_ptr<PointCollection> pPointCollection = std::make_shared<PointCollection>();

    // Create algorithm of type bresenham normal
    std::shared_ptr<BresenhamNormal> pAlgorithm = std::make_shared<BresenhamNormal>(pPointCollection);

    // Queue for all drawable objects
    std::unique_ptr<DrawableObjectsQueue> queue = std::make_unique<DrawableObjectsQueue>();

    // Create and push some random lines
    std::shared_ptr<Line> pLine1 = std::make_shared<Line>(pAlgorithm, Point(99, 2), Point(20, 20), Colors::red);
    queue->push(pLine1);
    std::shared_ptr<Line> pLine2 = std::make_shared<Line>(pAlgorithm, Point(34, 2), Point(65, 84), Colors::blue);
    queue->push(pLine2);
    std::shared_ptr<Line> pLine3 = std::make_shared<Line>(pAlgorithm, Point(7, 2), Point(56, 20), Colors::green);
    queue->push(pLine3);
    std::shared_ptr<Line> pLine4 = std::make_shared<Line>(pAlgorithm, Point(8, 34), Point(20, 87), Colors::black);
    queue->push(pLine4);

    // Finally generate the image
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
```

This code demonstrates how to create a bitmap image with multiple colored lines using the Bitmap Image Generator. You can find this example in the examples/api/ directory of the repository.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

    Thanks to Doxygen for providing a useful documentation generation tool.
    Special thanks to our contributors and the open-source community for their support and contributions to this project.

Happy image generation!
