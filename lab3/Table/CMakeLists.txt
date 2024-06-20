cmake_minimum_required(VERSION 3.28)
project(Table)

set(CMAKE_CXX_STANDARD 17)

add_executable(Table main.cpp
        KeyValueTable.cpp)
