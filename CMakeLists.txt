cmake_minimum_required(VERSION 3.27)
project(bitmap_image_generator)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O1")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)
add_subdirectory(examples/simple_image)
add_subdirectory(examples/black_and_white)
add_subdirectory(examples/chunk)
add_subdirectory(examples/chunk_speed)
add_subdirectory(examples/line)
# Here will be placed other subdirectories
