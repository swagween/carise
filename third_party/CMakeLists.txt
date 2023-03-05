include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(sfml
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab
)
FetchContent_MakeAvailable(sfml)
