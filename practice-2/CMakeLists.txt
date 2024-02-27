cmake_minimum_required(VERSION 3.27)

set(SOURCES practice_2.cpp)

add_library(practice-2 STATIC ${SOURCES})

target_include_directories(practice-2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
