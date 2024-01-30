cmake_minimum_required(VERSION 3.22)

add_library(demo_math STATIC "geometry.cpp" "geometry.h" "linalg.h" "linalg.cpp")
target_include_directories(demo_math PUBLIC .)