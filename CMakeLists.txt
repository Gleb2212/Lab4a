cmake_minimum_required(VERSION 3.17)
project(Lab4a C)

set(CMAKE_C_STANDARD 17)

add_executable(Lab4a main.c dialog/dialog.c dialog/dialog.h table/table.c table/table.h)