cmake_minimum_required(VERSION 2.8)

project(vmulTest)

set(CMAKE_CXX_FLAGS "-flax-vector-conversions")
add_executable(vmulTest vmul.cpp main.cpp)
