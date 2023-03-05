cmake_minimum_required (VERSION 3.24.0)

if (APPLE)
	set( CMAKE_CXX_COMPILER "/usr/bin/clang++" )
	set( CMAKE_C_COMPILER "/usr/bin/clang" )
endif()

project ("carise")

# set some variables
set(LIBRARY_PATH ${CMAKE_SOURCE_DIR}/3rdParty/)

# set the local include directory for the engine
set(CARISE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

# Include sub-projects.
add_subdirectory ("3rdParty")
add_subdirectory ("src")

