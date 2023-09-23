cmake_minimum_required(VERSION 3.17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_compile_options(-fno-omit-frame-pointer)
add_compile_options(-fno-omit-frame-pointer -mno-omit-leaf-frame-pointer)

project(sort)

find_package(GTest REQUIRED)

include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)