add_subdirectory(power)
add_subdirectory(sqrt)

add_library(advance_calc INTERFACE)
target_link_libraries(advance_calc INTERFACE power sqrt)
