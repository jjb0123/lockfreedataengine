cmake_minimum_required(VERSION 3.16)
project(lockfreedataengine VERSION 0.1 LANGUAGES CXX)

# Use C++20 because atomic<T> and memory order semantics are strongest here
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library
add_library(lfde INTERFACE)
target_include_directories(lfde INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# GoogleTest
enable_testing()
add_subdirectory(tests)
add_subdirectory(benchmarks)

