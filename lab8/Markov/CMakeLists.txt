cmake_minimum_required(VERSION 3.28)
project(Markov)

set(CMAKE_CXX_STANDARD 17)

add_executable(Markov main.cpp
        Markov.cpp
        MyString.cpp)
