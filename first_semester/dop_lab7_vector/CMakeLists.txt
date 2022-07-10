cmake_minimum_required(VERSION 3.20)
project(dop_lab7_vector)

set(CMAKE_CXX_STANDARD 14)
include_directories("inc/")
include_directories("src/")
add_executable(dop_laba7_vector main.cpp
        inc/functions.h
        src/Read.cpp
        src/Write.cpp
        src/Rabota-nad-vectorom.cpp)
