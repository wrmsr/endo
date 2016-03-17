# file(GLOB endo_iface "endo/*.hpp")
# file(GLOB endo_impl "endo/impl/*.cpp")
# file(GLOB endo_test "endo/test/*.cpp")

set(libendo_include include/endo/fib.hpp)
set(libendo_source source/endo/fib.cpp)
set(libendo_test test/endo/fib_test.cpp)

add_library(libendo ${libendo_include} ${libendo_source})
target_include_directories(libendo PUBLIC ./include)
