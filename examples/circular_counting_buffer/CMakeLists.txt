include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(circular_counting_buffer main.cpp)


target_link_libraries(circular_counting_buffer bitmap_image_generator)

