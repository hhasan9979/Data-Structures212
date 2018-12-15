cmake_minimum_required(VERSION 3.12)
project(assignment2)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp sequence1.cpp sequence1.h)
add_executable(exam sequence1.cpp sequence1.h sequence_exam.cpp)
add_executable(test sequence1.cpp sequence1.h sequence_test.cpp)