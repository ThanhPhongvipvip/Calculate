cmake_minimum_required(VERSION 3.10)
project(demoProj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/ListAllFile.cmake)

add_subdirectory(basic_calc)
add_subdirectory(advance_calc)

add_executable(demoProj main.cpp)
target_link_libraries(demoProj PRIVATE basic_calc advance_calc)
