cmake_minimum_required(VERSION 3.22)

add_subdirectory(app)
add_subdirectory(utils)
add_subdirectory(loaders)
add_subdirectory(types)

add_library(demo_common INTERFACE)
target_link_libraries(demo_common INTERFACE demo_types demo_math demo_loader spdlog::spdlog)
