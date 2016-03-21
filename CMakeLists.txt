cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Custom)
include(ExternalProject)

# add_definitions(-std=c++14)

project(endo)

add_subdirectory(external)
add_subdirectory(libendo)
add_subdirectory(endo)
