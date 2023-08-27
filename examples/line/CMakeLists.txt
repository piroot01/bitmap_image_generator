include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(line main.cpp)


target_link_libraries(line bitmap_image_generator)

