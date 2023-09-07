# Bitmap Image Generator

Bitmap Image Generator is a C++ program that allows you to create bitmap images by drawing simple lines from one point to another. It supports various features and is designed for ease of use and extensibility.

## Features

1. **Simple Line Drawing:** This program currently implements simple line drawing, allowing you to create lines from one point to another.

2. **Image Generation:** You can generate bitmap images using this program.

3. **CMake Build:** The program is compiled and built using CMake, making it easy to build on different platforms.

4. **Usage Example:** The main.cpp file serves as the API and demonstrates how to use the program to create bitmap images.

## Documentation

The documentation for this project is generated using Doxygen. You can generate the documentation by running the following command:

doxygen config

The documentation will be generated inside the 'doc' directory.

## Customization

    Line Color: You can specify the color of lines, and the program supports any 255-255-255 color.

    Max Image Resolution: The program supports a maximum image resolution of 4294967295 pixels.

    Extensible: The program is designed to be extensible and ready for various drawable objects such as circles, ovals, curves, and more. It also supports different algorithm implementations for each object for experimental purposes.
    Custom Exception Class: The program includes a custom exception class for handling errors and exceptions.

## To-Do List

 Support for more drawable objects, such as circles, ovals, and curves.

    Multithread the execution of drawable objects for improved performance. Note that with the current implementation, multithreading is not reasonable.

## Getting Started

To get started with Bitmap Image Generator, follow these steps:

    Clone this repository to your local machine:

    git clone https://github.com/yourusername/bitmap-image-generator.git

Build the program using CMake:

## License

This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

    Thanks to Doxygen for providing a useful documentation generation tool.
    Special thanks to our contributors and the open-source community for their support and contributions to this project.

Happy image generation!
