# CMakeList.txt : Top-level CMake project file
#
cmake_minimum_required(VERSION 3.19)
cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0092 NEW)
cmake_policy(SET CMP0111 NEW)

enable_testing()
project("cecko")

include("CMakeConf.cmake")

add_subdirectory("fmwk" "fmwk")
add_subdirectory("solution" "stud-sol")
add_subdirectory("main" "stud-main")