include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(black_and_white main.cpp)


target_link_libraries(black_and_white bitmap_image_generator)

