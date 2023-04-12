cmake_minimum_required(VERSION 3.25)
project(projectBinSearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(projectBinSearch main.cpp Graph.cpp Graph.h check.h check.cpp bfs.h bfs.cpp)
