cmake_minimum_required(VERSION 3.14)

project(SoftRenderer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fmt)

include_directories(include)
include_directories(tinyobjloader)

set(SRCS
    src/Model.cpp
)

enable_testing()
add_executable(OBJ_Loader_Test test/obj_loader.cpp ${SRCS})
add_test(NAME OBJ_Loader_Test COMMAND OBJ_Loader_Test)

add_executable(SoftRenderer src/main.cpp ${SRCS})
