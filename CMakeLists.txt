cmake_minimum_required(VERSION 3.19)
project(yahtzee)

set(CMAKE_CXX_STANDARD 17)

# where -Wall -Wextra -Wpedantic are extra compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(yahtzee src/main.cpp)