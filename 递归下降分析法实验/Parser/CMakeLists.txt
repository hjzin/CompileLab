cmake_minimum_required(VERSION 3.8)
project(Parser)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c parser.h)
add_executable(Parser ${SOURCE_FILES})