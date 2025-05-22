cmake_minimum_required(VERSION 3.30.5)
project(DMathBool3)

set(CMAKE_CXX_STANDARD 20)

add_executable(DMathBool3 main.cpp
        src/BoolTable.cpp
        include/BoolTable.h)
