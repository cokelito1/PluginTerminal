cmake_minimum_required(VERSION 2.6)
project(EchoPlugin)

set(EchoPluginSRC "src/EchoPlugin.cpp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)

include_directories(include)
include_directories(../include)

add_library(EchoPlugin SHARED ${EchoPluginSRC})
