cmake_minimum_required(VERSION 2.6)
project(endo)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# file(GLOB endo_iface "endo/*.hpp")
# file(GLOB endo_impl "endo/impl/*.cpp")
# file(GLOB endo_test "endo/test/*.cpp")
set(endo_iface endo/fib.hpp)
set(endo_impl endo/impl/fib.cpp)
set(endo_test endo/test/fib_test.cpp)

add_library(endo ${endo_iface} ${endo_impl})
# target_include_directories(endo ${CMAKE_CURRENT_SOURCE_DIR})


set(endo_exe_iface)
set(endo_exe_impl endo_exe/impl/main.cpp)
set(endo_exe_test)

add_executable(endo_exe ${endo_exe_iface} ${endo_exe_impl})
target_link_libraries(endo_exe endo)
