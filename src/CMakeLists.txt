cmake_minimum_required(VERSION 3.10)

#Putting everything but main() in a library makes testing easier.
add_library (CodeLib code.cpp code.hpp)

#Build the executable.
add_executable(main main.cpp)
target_link_libraries(main CodeLib)
