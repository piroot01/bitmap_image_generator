include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB SOURCES
    "image/*.cpp"
    "colors/*.cpp"
    "writer/*.cpp"
    "chunk/*.cpp"
    "exception/*.cpp"
    "utils/*.cpp"
    "image_objects/*.cpp"
    "algorithms/*.cpp"
    "processors/*.cpp"
    "managers/*.cpp"
    "parameters/*.cpp"
    "preparators/*.cpp"
)


add_library(bitmap_image_generator ${SOURCES})
