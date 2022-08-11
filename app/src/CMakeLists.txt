project($PROJECT_NAME)


# Adding executable
add_executable(main main/main.c)
target_link_libraries(main
    PRIVATE
    printhello)

# Adding libraries
add_library(printhello printhello/printhello.c)
target_include_directories(printhello 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)
