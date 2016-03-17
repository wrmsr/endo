set(endo_include)
set(endo_source source/endo/main.cpp)
set(endo_test)

add_executable(endo ${endo_source})
target_link_libraries(endo libendo)
