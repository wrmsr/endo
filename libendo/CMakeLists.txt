# file(GLOB endo_iface "endo/*.hpp")
# file(GLOB endo_impl "endo/impl/*.cpp")
# file(GLOB endo_test "endo/test/*.cpp")

set(libendo_iface endo/fib.hpp)
set(libendo_impl endo/impl/fib.cpp)
set(libendo_test endo/test/fib_test.cpp)

add_library(libendo ${libendo_iface} ${libendo_impl})
target_include_directories(libendo PUBLIC ./)
