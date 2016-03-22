file(GLOB_RECURSE ftl_include ${CMAKE_CURRENT_SOURCE_DIR}/ftl/include *.h *.hpp)
add_library(ftl INTERFACE)
target_sources(ftl INTERFACE ${ftl_include})
target_include_directories(ftl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/ftl/include)
