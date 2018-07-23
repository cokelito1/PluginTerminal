cmake_minimum_required(VERSION 2.6)
project(Plugins)

include_directories(include)

add_subdirectory(pingPlugin)
add_subdirectory(echoPlugin)
add_subdirectory(systemPlugin)
add_subdirectory(nekoPlugin)
