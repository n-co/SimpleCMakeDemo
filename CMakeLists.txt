cmake_minimum_required(VERSION 3.22)

project(
	SimpleCMakeDemo
	VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)
include(cmake/Utilities.cmake)

add_subdirectory(dependencies)

add_subdirectory(src)


add_subdirectory(tests)