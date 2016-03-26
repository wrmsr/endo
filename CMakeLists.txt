cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Custom)
include(ExternalProject)

# add_definitions(-std=c++14)

enable_language(CXX)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")

project(endo)

add_subdirectory(external)
add_subdirectory(libendo)
add_subdirectory(endo)
