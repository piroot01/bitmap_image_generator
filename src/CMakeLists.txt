include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB SOURCES "image/*.cpp")


add_library(bitmap_image_generator ${SOURCES})
