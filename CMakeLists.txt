cmake_minimum_required(VERSION 3.22)

project(
	SimpleCMakeDemo
	VERSION 0.0.1
)

include(cmake/CPM.cmake)
include(cmake/Utilities.cmake)

add_subdirectory(dependencies)