cmake_minimum_required(VERSION 3.28)
project(PolishNotation)

set(CMAKE_CXX_STANDARD 17)

add_executable(PolishNotation main.cpp
        ReverseEntry.cpp
        ReverseEntry.h)
