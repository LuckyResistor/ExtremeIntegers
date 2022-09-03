cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(02-literals src/main.cpp)
add_dependencies(02-literals common)
target_link_libraries(02-literals common)
target_compile_features(02-literals PUBLIC cxx_std_17)
target_include_directories(02-literals PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
