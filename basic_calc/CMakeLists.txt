add_subdirectory(add)
add_subdirectory(subtract)
add_subdirectory(multiply)
add_subdirectory(divide)

add_library(basic_calc INTERFACE)
target_link_libraries(basic_calc INTERFACE add subtract multiply divide)
