cmake_minimum_required(VERSION 3.20)

project(TD01)

file(GLOB_RECURSE EXO1 CONFIGURE_DEPENDS src1/*)
file(GLOB_RECURSE EXO2 CONFIGURE_DEPENDS src2/*)

add_executable(exo1 ${EXO1})
add_executable(exo2 ${EXO2})

target_compile_features(exo1 PRIVATE cxx_std_17)
target_compile_features(exo2 PRIVATE cxx_std_17)

set_target_properties(exo1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set_target_properties(exo2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})