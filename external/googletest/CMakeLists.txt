# DISABLE CMP0037: Target names should not be reserved and should match a validity pattern.
set_policy(CMP0037 OLD)

# Function: Build test and add command to execute it via target 'test'
function(add_test_without_ctest target)
  add_subdirectory(${target})

  if(NOT TARGET ${target})
    return()
  endif()

  add_dependencies(test ${target})
  add_custom_command(TARGET test POST_BUILD
    COMMAND $<TARGET_FILE:${target}> --gtest_output=xml:gtests-${target}.xml)
endfunction()

set(gmock_build_tests           OFF CACHE BOOL "")
set(gtest_build_samples         OFF CACHE BOOL "")
set(gtest_build_tests           OFF CACHE BOOL "")
set(gtest_disable_pthreads      OFF CACHE BOOL "")
set(gtest_force_shared_crt      ON  CACHE BOOL "")
set(gtest_hide_internal_symbols OFF CACHE BOOL "")

add_subdirectory(googletest)

# Create interface library to link against gmock
add_library(googletest INTERFACE)

target_include_directories(googletest
    SYSTEM INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
)

target_link_libraries(googletest
    INTERFACE
    gtest
)

add_custom_target(test)
set_target_properties(test PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
