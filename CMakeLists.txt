cmake_minimum_required(VERSION 4.0)
project(PlotvaNEW)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlotvaNEW main.cpp
        Cell.cpp
        Cell.hpp
        Plotva.cpp
        Plotva.hpp)
