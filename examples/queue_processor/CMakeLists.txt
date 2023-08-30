include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(queue_processor main.cpp)


target_link_libraries(queue_processor bitmap_image_generator)

