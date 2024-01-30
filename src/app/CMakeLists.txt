cmake_minimum_required(VERSION 3.22)

add_executable(DemoApp "DemoApp.cpp")
target_link_libraries(DemoApp PRIVATE demo_common)
