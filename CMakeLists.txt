cmake_minimum_required(VERSION 3.25)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(ray_tracing src/main.cpp src/Vector3.cpp src/Vector3.h src/Ray.cpp src/Ray.h src/Ray.h src/Ray.cpp src/Hittable.cpp src/Hittable.h src/Sphere.cpp src/Sphere.h src/World.cpp src/World.h src/utils.cpp src/utils.h src/Camera.cpp src/Camera.h)
