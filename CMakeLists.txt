cmake_minimum_required(VERSION 3.10)

project(CMakeGTestExample VERSION 1.0
                  DESCRIPTION "CMake example using GoogleTest as a submodule."
                  LANGUAGES CXX)

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    add_subdirectory(tests)
endif()