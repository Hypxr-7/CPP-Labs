cmake_minimum_required(VERSION 3.26)
project(OOP_Lab_10)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(q1 q1.cpp)
add_executable(q2 q2.cpp)
add_executable(q3 q3.cpp)

configure_file(words5.txt words5.txt COPYONLY)