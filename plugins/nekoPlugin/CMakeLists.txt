cmake_minimum_required(VERSION 2.6)
project(NekoPlugin)

set(NekoPluginSRC "src/NekoPlugin.cpp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)

set(USE_SYSTEM_CURL "ON")
set(BUILD_CPR_TESTS "OFF")

add_definitions("-fPIC")

add_subdirectory(cpr)
include_directories(${CPR_INCLUDE_DIRS})
include_directories(include)
include_directories(../include)

add_library(NekoPlugin SHARED ${NekoPluginSRC})
target_link_libraries(NekoPlugin ${CPR_LIBRARIES})
