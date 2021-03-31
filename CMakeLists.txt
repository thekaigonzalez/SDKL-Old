# cmake_minimum_required(VERSION <specify CMake version here>)
project(SDK_L C CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(sdkl main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(sdkg parser/grouper.cpp)
add_executable(spm misc/spm.cxx)
add_executable(scc compiler/compiler.cpp)