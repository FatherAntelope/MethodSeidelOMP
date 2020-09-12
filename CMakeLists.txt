cmake_minimum_required(VERSION 3.17)
project(lr2)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(lr2 main.cpp FileTransfer.cpp FileTransfer.h MethodSeidel.cpp MethodSeidel.h)