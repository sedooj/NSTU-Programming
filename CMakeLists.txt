cmake_minimum_required(VERSION 3.27)
project(programming)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(lab-1)
add_subdirectory(practic-1)

add_executable(programming main.cpp)

#target_link_libraries(programming PRIVATE lab-1)
target_link_libraries(programming PRIVATE practic-1)