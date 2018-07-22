cmake_minimum_required(VERSION 2.6)
project(main)

include_directories("include")
include_directories("plugins/include")

add_definitions("-rdynamic -ldl")
set (CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES LINK_FLAGS -ldl)
target_link_libraries(main stdc++fs)

add_subdirectory(plugins)
