cmake_minimum_required(VERSION 3.22)
enable_testing()

add_executable(demo_tests "math_tests.cpp")
target_link_libraries(demo_tests PRIVATE demo_math GTest::gtest_main)

add_test(demo_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/demo_tests)