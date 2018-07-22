cmake_minimum_required(VERSION 2.6)
project(PingPlugin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)
set(PingPluginSRC "src/PingPlugin.cpp")

include_directories(include)
include_directories(../include)

add_library(PingPlugin SHARED ${PingPluginSRC})
