cmake_minimum_required(VERSION 3.14)

project(SoftRenderer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)



include_directories(include)
include_directories(tinyobjloader)
include_directories(fmt/include)
include_directories(eigen)

link_directories(${PROJECT_SOURCE_DIR}/libs)


set(SRCS
    src/Model.cpp
    src/Picture.cpp
    src/MVP.cpp
)


enable_testing()
add_executable(OBJ_Loader_Test test/obj_loader.cpp ${SRCS})
target_link_libraries(OBJ_Loader_Test libfmt.a)
add_test(NAME OBJ_Loader_Test COMMAND OBJ_Loader_Test)

add_executable(Pic_Test test/pic_test.cpp src/Picture.cpp)
target_link_libraries(Pic_Test libfmt.a)
add_test(NAME PIC_Test COMMAND Pic_Test)

add_executable(Eigen_Test test/Eigen_test.cpp)
add_test(NAME EIGEN_Test COMMAND Eigen_Test)

add_executable(MVP_Test test/MVP_test.cpp src/MVP.cpp)
add_test(NAME MVP_Test COMMAND MVP_Test)

add_executable(SoftRenderer src/main.cpp ${SRCS})
target_link_libraries(SoftRenderer libfmt.a)
