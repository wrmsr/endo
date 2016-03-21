find_package(Boost 1.60 COMPONENTS filesystem regex system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(libendo_include
        include/endo/endo.hpp
        )
set(libendo_source
        source/endo/endo.cpp
        )
set(libendo_test
        test/endo/main.cpp
        test/endo/endo_test.cpp
        )
set(libendo_libs
        glog
        fruitext
        ${Boost_LIBRARIES}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        )

add_library(libendo ${libendo_include} ${libendo_source})
set_target_properties(libendo PROPERTIES COMPILE_FLAGS -std=c++14)
target_include_directories(libendo PUBLIC ./include)
target_link_libraries(libendo ${libendo_libs})

add_executable(testlibendo ${libendo_include} ${libendo_test})
target_link_libraries(testlibendo libendo ${libendo_libs} googletest)
