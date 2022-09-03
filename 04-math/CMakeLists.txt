cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(04-math src/main.cpp)
add_dependencies(04-math common)
target_link_libraries(04-math common)
target_compile_features(04-math PUBLIC cxx_std_17)
target_include_directories(04-math PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
