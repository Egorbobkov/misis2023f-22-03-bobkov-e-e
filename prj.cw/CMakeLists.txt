find_package(OpenCV REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${OpenCV_LIBS} )