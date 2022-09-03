cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(01-types src/main.cpp)
add_dependencies(01-types common)
target_link_libraries(01-types common)
target_compile_features(01-types PUBLIC cxx_std_17)
target_include_directories(01-types PUBLIC "${PROJECT_SOURCE_DIR}/common/src")
