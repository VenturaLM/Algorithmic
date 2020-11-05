cmake_minimum_required (VERSION 3.1)
project (main)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp heapsort.cpp iterativeDeterminant.cpp recursiveDeterminant.cpp statisticsFunctions.cpp sistemaEcuaciones.cpp filesFunctions.cpp)