cmake_minimum_required (VERSION 3.24.0)

project(BuildLibraries)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES true)
# add all libraries that need to be built
add_subdirectory("SFML")
