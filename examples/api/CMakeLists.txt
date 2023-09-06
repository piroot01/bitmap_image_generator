include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(api main.cpp)


target_link_libraries(api bitmap_image_generator)

