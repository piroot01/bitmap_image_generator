include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(simple_image main.cpp)


target_link_libraries(simple_image bitmap_image_generator)

