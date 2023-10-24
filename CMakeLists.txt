cmake_minimum_required(VERSION 3.9)

project("t113-s3-hal")

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(
    ${INCLUDES}
)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/std/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/std/*.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDES}
)