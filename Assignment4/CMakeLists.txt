cmake_minimum_required(VERSION 3.12)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp sequence3.cpp sequence3.h)
add_executable(exam sequence3.cpp sequence3.h sequence3_exam.cpp node1.cpp node1.h)
add_executable(test sequence3.cpp sequence3.h sequence3_test.cpp)