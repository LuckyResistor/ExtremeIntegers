cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(03-negation src/main.cpp)
add_dependencies(03-negation common)
target_link_libraries(03-negation common)
target_compile_features(03-negation PUBLIC cxx_std_17)
target_include_directories(03-negation PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
