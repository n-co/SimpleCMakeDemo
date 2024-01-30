cmake_minimum_required(VERSION 3.22)

add_library(demo_loader STATIC "DemoLoader.cpp" "DemoLoader.h")
target_link_libraries(demo_loader PRIVATE nlohmann_json spdlog::spdlog)
target_include_directories(demo_loader PUBLIC .)