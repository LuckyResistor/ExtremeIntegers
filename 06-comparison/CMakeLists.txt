cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(06-comparison src/main.cpp)
add_dependencies(06-comparison common)
target_link_libraries(06-comparison common)
target_compile_features(06-comparison PUBLIC cxx_std_17)
target_include_directories(06-comparison PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
