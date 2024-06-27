cmake_minimum_required(VERSION 3.24)

project(glmods-sdk
    VERSION 0.0.1
    LANGUAGES C CXX)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "Only 32bits builds are supported")
endif()

if(NOT WIN32)
    message(FATAL_ERROR "Only Windows builds are supported")
endif()

option(GLMODS_BUILD_VALIDATOR "Whether the GLMods plugin validator should be built" OFF)
option(GLMODS_BUILD_SAMPLE "Whether the sample GLMods plugin should be built" OFF)

add_library(glmods_sdk INTERFACE)
target_include_directories(glmods_sdk INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(GLMods::SDK ALIAS glmods_sdk)

function(add_glplugin NAME)
    add_library(${NAME} MODULE ${ARGN})
    target_link_libraries(${NAME} PRIVATE GLMods::SDK)
    set_target_properties(${NAME} PROPERTIES SUFFIX ".glplugin")
endfunction()

if(GLMODS_BUILD_VALIDATOR)
    add_executable(glvalidate "${CMAKE_CURRENT_SOURCE_DIR}/src/glvalidate.cpp")
    target_link_libraries(glvalidate PRIVATE GLMods::SDK)
    set_target_properties(glvalidate
        PROPERTIES
        CXX_STANDARD 20)
endif()

if(GLMODS_BUILD_SAMPLE)
    add_glplugin(glsample "${CMAKE_CURRENT_SOURCE_DIR}/src/sample.c")
endif()