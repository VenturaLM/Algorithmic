cmake_minimum_required (VERSION 3.1)
project (graphs)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
add_executable(nQueens main.cpp n_queens_las_vegas.cpp)
