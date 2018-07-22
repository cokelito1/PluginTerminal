cmake_minimum_required(VERSION 2.6)
project(SystemPlugin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)
set(SystemPluginSRC "src/SystemPlugin.cpp")

include_directories(include)
include_directories(../include)

add_library(SystemPlugin SHARED ${SystemPluginSRC})
