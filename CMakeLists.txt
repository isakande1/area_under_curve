cmake_minimum_required(VERSION 3.26)
project(area C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Wall -Wextra -Wpedantic -Werror -lm -fopenmp" )

add_executable(area main.c)
