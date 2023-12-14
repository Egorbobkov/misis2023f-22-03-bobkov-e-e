cmake_minimum_required(VERSION 3.20)
project(bobkov-e-e)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
find_package(OpenCV REQUIRED)

add_subdirectory(prj.codeforces)
add_subdirectory(prj.cw)