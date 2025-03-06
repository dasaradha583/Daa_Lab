cmake_minimum_required(VERSION 3.30)
project(Daa_Lab C)

set(CMAKE_C_STANDARD 11)

add_library(Daa_Lab STATIC library.c
        "Lab Programs/1stLesson/MinMax.c"
        "Lab Programs/2ndLesson/OptimalTapes.c")
