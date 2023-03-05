cmake_minimum_required(VERSION 3.11)
project(carise)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
)
