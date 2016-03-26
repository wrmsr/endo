set_policy(CMP0037 OLD)
set(CMAKE_MACOSX_RPATH 1)

add_subdirectory(fruit/configuration)

configure_file(
    fruit/configuration/fruit-config-base.h.in
    fruit/impl/fruit-config-base.h
)

add_library(fruit
    fruit/src/demangle_type_name.cpp
    fruit/src/component_storage.cpp
    fruit/src/injector_storage.cpp
    fruit/src/normalized_component_storage.cpp
    fruit/src/semistatic_map.cpp
)

target_compile_options(fruit PRIVATE
    -std=c++14
)

target_include_directories(fruit PUBLIC
    fruit/include
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)
