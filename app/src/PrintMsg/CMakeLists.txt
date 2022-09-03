project(printmsg)


set(SOURCE_FILES 
    print.cpp
)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/PrintMsg)


add_library(${PROJECT_NAME} ${SOURCE_FILES})


target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${INCLUDE_DIR})
