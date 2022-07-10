cmake_minimum_required(VERSION 3.20)
project(dop_lab5_delete_and_copied)

set(CMAKE_CXX_STANDARD 14)
include_directories("inc/")
include_directories("src/")
add_executable(dop_lab5_delete_and_copied main.cpp
        inc/functions.h
        src/Read.cpp
        src/Write.cpp
        src/Rabota-nad-massivom.cpp)
