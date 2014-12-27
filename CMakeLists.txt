cmake_minimum_required(VERSION 2.8.4)
project(stateMachineInverterAlpha)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES inverterFSM.c)
add_executable(stateMachineInverterAlpha ${SOURCE_FILES})