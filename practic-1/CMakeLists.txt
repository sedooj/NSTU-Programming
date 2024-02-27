cmake_minimum_required(VERSION 3.27)

set(SOURCES practic_1.cpp)

add_library(practic-1 STATIC ${SOURCES})

target_include_directories(practic-1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
