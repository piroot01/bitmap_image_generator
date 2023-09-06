include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(image_task_manager main.cpp)


target_link_libraries(image_task_manager bitmap_image_generator)

