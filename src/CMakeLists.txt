cmake_minimum_required(VERSION 3.24.0)
project(carise)

# debug build
set(CMAKE_BUILD_TYPE DEBUG)
# c++ standard
set(CMAKE_CXX_STANDARD 20)

# includes and stuff
include_directories(
PRIVATE
	# library local include directory
	${CARISE_INCLUDE_DIR}

	# SFML
	${LIBRARY_PATH}/SFML/include/
)

add_executable(carise
	"utility/benchmark.cpp"
	"utility/logger.cpp"

	"main.cpp"
)

# link some libraries
target_link_libraries(carise
PRIVATE
	# SFML graphics and windowing libraries
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-system
)

target_precompile_headers(carise
PUBLIC
	<vector>
	<iostream>
	<fstream>
	<deque>
	<string>
	<map>
	<unordered_map>
	<array>
	<algorithm>
	<chrono>
	<utility>
	<filesystem>
	<stddef.h>
	<stdint.h>
	<wchar.h>
	<functional>
	<cmath>
)
