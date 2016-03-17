set(endo_iface)
set(endo_impl endo/impl/main.cpp)
set(endo_test)

add_executable(endo ${endo_iface} ${endo_impl})
target_link_libraries(endo libendo)
