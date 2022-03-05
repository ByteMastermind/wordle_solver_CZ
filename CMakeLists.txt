cmake_minimum_required(VERSION 3.21)
project(wordle_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(wordle_solver
        src/main.cpp
        src/Dictionary.cpp
        src/Interface.cpp)
