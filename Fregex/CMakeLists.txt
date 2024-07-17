# set cmake version
cmake_minimum_required(VERSION 3.10)

# project
project(Fregex)

# set cpp standard
set(CMAKE_CXX_STANDARD 20)

# add source files
file(GLOB_RECURSE "Source Files/*.cpp")

# add header files
include_directories("Header Files")

# add executables
add_executable(Fregex ${SOURCES})