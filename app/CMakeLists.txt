cmake_minimum_required(VERSION ${CMAKE_VERSION})


# Project name
project($ENV{PROJECT_NAME} LANGUAGES C CXX)


# Add the modules of the program
add_subdirectory(include)
add_subdirectory(src)


# Create an CMake option to build the examples for the libs
option(BUILD_EXAMPLE "Build the libraries examples" OFF)

if (BUILD_EXAMPLE)
    message(STATUS "Building examples...")
    #add_subdirectory(examples)
endif()
