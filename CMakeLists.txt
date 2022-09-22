cmake_minimum_required(VERSION 3.14)

project(SoftRenderer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(tinyobjloader)

set(SRCS
    src/main.cpp
)

add_executable(SoftRenderer ${SRCS})