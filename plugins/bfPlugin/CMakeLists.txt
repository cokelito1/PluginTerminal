cmake_minimum_required(VERSION 2.6)
project(BfPlugin)

set(BfPluginSRC "src/BfPlugin.cpp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)

include_directories(include)
include_directories(../include)

add_library(BfPlugin SHARED ${BfPluginSRC} src/BfInterpreter.cpp)
