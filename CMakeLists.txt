# cmake_minimum_required(VERSION <specify CMake version here>)
project(SDK_L C CXX)

set(CMAKE_CXX_STANDARD 11)




set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
###################################################
#
#               IMPLEMENT CORE MODULES
#
###################################################


add_executable(sdko main.cpp)
add_executable(sdkg parser/grouper.cpp)
add_executable(spm misc/spm.cxx)
add_executable(scc compiler/compiler.cpp)


#################################################
#
#
#              IMPLEMENT TESTS
#
#
#################################################



add_executable(maintestone api/tests/ordered_map.cpp)



###################################################
#
#
#           INSERT SDK PROJECT BUILD FILES
#
#
###################################################


add_executable(sdkp projects/sdkproj-run.cpp)

####################################################
#
#
#           SDK STANDARDS
#
#
####################################################

add_executable(sdkl standards/1.0/1.0.cpp)


####################################################
#
#
#       IMPLEMENTING BINARY DIRECTORIES
#
#
####################################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   "../bin")