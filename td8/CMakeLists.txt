cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

project(TD08)

file(GLOB_RECURSE EXO1 CONFIGURE_DEPENDS exo1/*)

add_executable(exo1 ${EXO1})

set_target_properties(exo1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})