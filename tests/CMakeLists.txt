cmake_minimum_required(VERSION 3.10)

#Build GoogleTest
option(INSTALL_GTEST "" OFF) #Linking to a local copy is the point of this exercise.
option(BUILD_GMOCK "" OFF) #We're only using GTest in this example.
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

#Build the tests
set(CMAKE_CXX_STANDARD 11) #Required to use googletest headers.

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include
)

add_executable(CodeTest code.test.cpp)
target_link_libraries(CodeTest CodeLib gtest gtest_main)

#Add tests to CTest
include(GoogleTest)
enable_testing()
gtest_add_tests(TARGET CodeTest TEST_SUFFIX .noArgs TEST_LIST noArgsTests)

#Add "make check" target as workaround for "make test" bug in CMake.
if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -V DEPENDS CodeTest)
endif()