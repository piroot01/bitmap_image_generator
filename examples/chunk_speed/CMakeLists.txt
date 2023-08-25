include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(chunk_speed main.cpp)


target_link_libraries(chunk_speed bitmap_image_generator)

