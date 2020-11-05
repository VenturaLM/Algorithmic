cmake_minimum_required (VERSION 3.1)
project (main)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp matrix.cpp exponentiation.cpp ClaseTiempo.cpp filesFunctions.cpp)
