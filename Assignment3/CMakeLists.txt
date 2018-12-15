cmake_minimum_required(VERSION 3.12)
project(assignment3)

set(CMAKE_CXX_STANDARD 14)

add_executable(test sequence2.cpp sequence2.h sequence2_test.cpp)
add_executable(exam sequence2.cpp sequence2.h sequence2_exam.cpp )
add_executable(main main.cpp sequence2.cpp sequence2.h )