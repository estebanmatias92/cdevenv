cmake_minimum_required(VERSION 3.16)

# Project name
project(cdevenv)


# Add the modules of the program
add_subdirectory(include)
add_subdirectory(src)


# Create an CMake option to build the examples for the libs
option(BUILD_EXAMPLE "Build the libraries examples" ON)

if (BUILD_EXAMPLE)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()
