project(${PROJECT_NAME})

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/PrintMsg)


# Adding executable
add_executable(${PROJECT_NAME} 
    main.cpp
)

add_subdirectory(PrintMsg)

target_link_libraries(${PROJECT_NAME} PRIVATE printmsg)

