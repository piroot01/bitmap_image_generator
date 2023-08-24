include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(chunk main.cpp)


target_link_libraries(chunk bitmap_image_generator)

