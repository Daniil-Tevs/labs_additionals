cmake_minimum_required(VERSION 3.20)
project(2semester_lab10)

set(CMAKE_CXX_STANDARD 14)
include_directories("inc/")
add_executable(2semester_lab10 main.cpp inc/matrix.h inc/bmp.h src/bmp.cpp)
