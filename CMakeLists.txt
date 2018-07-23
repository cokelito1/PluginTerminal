cmake_minimum_required(VERSION 2.6)
project(CTerminal)

include_directories("include")
include_directories("plugins/include")

add_definitions("-rdynamic -ldl -lcpr")
set (CMAKE_CXX_STANDARD 17)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_SOURCE_GENERATOR "TBZ2")

set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;/.bzr/;~$;${CPACK_SOURCE_IGNORE_FILES}")

include(CPack)

add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES LINK_FLAGS -ldl)
target_link_libraries(main stdc++fs)

add_subdirectory(plugins)
