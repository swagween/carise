include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

FetchContent_Declare(sfml
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab
)

FetchContent_MakeAvailable(sfml)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG a33701196adfad74917046096bf5a2aa0ab0bb50
)

FetchContent_MakeAvailable(fmt)
