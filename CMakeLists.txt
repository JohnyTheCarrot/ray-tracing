cmake_minimum_required(VERSION 3.25)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenMP REQUIRED)

add_executable(ray_tracing src/main.cpp src/Vector3.cpp src/Vector3.h src/Ray.cpp src/Ray.h src/Ray.h src/Ray.cpp src/Hittable.cpp src/Hittable.h src/Sphere.cpp src/Sphere.h src/World.cpp src/World.h src/utils.cpp src/utils.h src/Camera.cpp src/Camera.h src/Materials/Material.cpp src/Materials/Material.h src/Materials/Lambert.cpp src/Materials/Lambert.h src/Materials/Metal.cpp src/Materials/Metal.h)

target_link_libraries(
        "${PROJECT_NAME}" PRIVATE
        OpenMP::OpenMP_CXX
)
