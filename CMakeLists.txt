cmake_minimum_required(VERSION 3.1)

project(lang_exp CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

add_subdirectory(src)
add_subdirectory(test)

