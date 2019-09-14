cmake_minimum_required(VERSION 3.14)
project(Cities)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_CXX_STANDARD 11)

add_executable(Cities main.cpp)