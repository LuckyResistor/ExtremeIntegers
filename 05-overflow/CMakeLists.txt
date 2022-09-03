cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(05-overflow src/main.cpp)
add_dependencies(05-overflow common)
target_link_libraries(05-overflow common)
target_compile_features(05-overflow PUBLIC cxx_std_17)
target_include_directories(05-overflow PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
