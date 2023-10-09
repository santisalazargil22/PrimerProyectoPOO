cmake_minimum_required(VERSION 3.26)
project(Primer_Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Primer_Proyecto main.cpp
        aeronave.cpp
        aeronave.h
        avion.cpp
        avion.h)
