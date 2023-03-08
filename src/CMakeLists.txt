set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
  "main.cpp"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE

  # SFML graphics and audio libraries
  sfml-graphics
  sfml-audio

  # utility libraries
  fmt::fmt
)

if(CARISE_USE_PCH)
  target_precompile_headers(${PROJECT_NAME} PRIVATE
    <array>
    <algorithm>
    <chrono>
    <concepts>
    <cstddef>
    <cstdint>
    <cmath>
    <deque>
    <functional>
    <iostream>
    <filesystem>
    <fstream>
    <map>
    <string>
    <unordered_map>
    <utility>
    <vector>
  )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type
  )
endif()

if(CMAKE_GENERATOR MATCHES "^(Visual Studio)")
  target_compile_options(${PROJECT_NAME} PUBLIC /MP)
endif()
