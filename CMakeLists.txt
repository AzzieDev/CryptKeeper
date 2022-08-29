# cmake_minimum_required(VERSION <specify CMake version here>)
project(Cryptkeeper)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Cryptkeeper
        crypt.cpp
        crypt.h)
