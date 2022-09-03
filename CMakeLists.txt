cmake_minimum_required(VERSION 3.18)
project(ExtremeIntegers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(01-types)
add_subdirectory(02-literals)
add_subdirectory(03-negation)
add_subdirectory(04-math)
add_subdirectory(05-overflow)
add_subdirectory(06-comparison)
add_subdirectory(common)


