cmake_minimum_required(VERSION 3.18.0)

project("carise")

option(CARISE_USE_PCH "Use precompiled headers" ON)

add_subdirectory("third_party")
add_subdirectory("src")
