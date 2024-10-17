cmake_minimum_required(VERSION 3.16.3)
project(MultiThreading VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(MultiThreading
    # src/main.cpp
    src/mainAtomic.cpp
    )

    # Link pthread library
target_link_libraries(MultiThreading pthread)