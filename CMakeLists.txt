
cmake_minimum_required(VERSION 3.16)
project(SDK_L C CXX)
include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -std=c++0x -lcurlpp -lcurl")
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
add_executable(sdki driver/mx.cpp)
add_executable(fbswk driver/filename_base.cpp)


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

#####################################################
#
#
#           VERSION CHECKING HANDLERS
#
#
#####################################################


add_executable(sdkv driver/dev.cpp)

####################################################
#
#
#   ASSERT SCRIPT VALIDATORS
#
#
####################################################


add_executable(mshift bypass/shift.cc)
add_executable(msj bypass/recent.cxx)
