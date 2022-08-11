project(${PROJECT_NAME})


# Adding executable
add_executable(testprinthello testprinthello.c)

# Link the libraries to use
target_link_libraries(testprinthello
    PRIVATE
    printhello)