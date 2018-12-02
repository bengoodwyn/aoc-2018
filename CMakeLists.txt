cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

include_directories(include /usr/local/include)
add_subdirectory(vendor/googletest)

project(aoc-2018)

file(GLOB TEST_CPP_FILES test/**.cpp)

add_executable(unittest ${TEST_CPP_FILES})
target_link_libraries(unittest gtest gtest_main)
enable_testing()
add_test(NAME unittest COMMAND unittest)

add_executable(aoc-2018 main.cpp)
