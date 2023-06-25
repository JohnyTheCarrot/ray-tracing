cmake_minimum_required(VERSION 3.25)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(ray_tracing src/main.cpp src/Vector3.cpp src/Vector3.h)
