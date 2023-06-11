cmake_minimum_required(VERSION 3.24)
project(RayTracingOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(RayTracingOneWeekend main.cpp vec3.h color.h ray.h hittable.h sphere.h hittable_list.h rtweekend.h camera.h)
