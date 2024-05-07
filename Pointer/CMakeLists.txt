cmake_minimum_required(VERSION 3.26)
project(Pointer C)

set(CMAKE_C_STANDARD 11)

add_executable(Pointer main.c
        libs/Shape.c
        libs/Shape.h
        libs/Rectangle.c
        libs/Rectangle.h)
