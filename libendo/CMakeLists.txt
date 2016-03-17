set(libendo_include include/endo/fib.hpp)
set(libendo_source source/endo/fib.cpp)
set(libendo_test test/endo/main.cpp test/endo/fib_test.cpp)

add_library(libendo ${libendo_include} ${libendo_source})
target_include_directories(libendo PUBLIC ./include)

add_executable(testlibendo ${libendo_include} ${libendo_test})
target_link_libraries(testlibendo libendo google::googletest)
