cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(common src/TypeInfo.hpp src/dummy.cpp src/IntegerToString.hpp)
