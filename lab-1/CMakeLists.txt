cmake_minimum_required(VERSION 3.27)

set(SOURCES lab_1.cpp)

add_library(lab-1 STATIC ${SOURCES})

target_include_directories(lab-1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
