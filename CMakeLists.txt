cmake_minimum_required(VERSION 3.0)

project(cryptkeeper)

# C++ standard libraries bundled
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(CMAKE_BUILD_TYPE Release)

include_directories(.)

add_executable(cryptkeeper
        crypt.cpp
        crypt.h)

# for Windows, using boost 1.81.0 in the below path, uncomment
#include_directories("C:/Program Files/Boost/boost_1_81_0/")

# for Windows to not need Visual C++ runtime installed
#set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /NODEFAULTLIB:MSVCRT")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

