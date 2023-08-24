include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB SOURCES "image/*.cpp" "colors/*.cpp" "writer/*.cpp" "image_chunk/*.cpp")


add_library(bitmap_image_generator ${SOURCES})
