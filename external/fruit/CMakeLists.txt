# DISABLE CMP0037: Target names should not be reserved and should match a validity pattern.
set_policy(CMP0037 OLD)

add_subdirectory(fruit)

target_include_directories(fruit PUBLIC fruit/include)

# Create interface library to link against gmock
add_library(fruitext INTERFACE)

target_include_directories(fruitext
    SYSTEM INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/fruit/include
)

target_link_libraries(fruitext
    INTERFACE
    fruit
)
