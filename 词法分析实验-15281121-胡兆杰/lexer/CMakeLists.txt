cmake_minimum_required(VERSION 3.8)
project(Lexer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lexer.h lexer.cpp)
add_executable(Lexer ${SOURCE_FILES})