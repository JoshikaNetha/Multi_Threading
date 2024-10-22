cmake_minimum_required(VERSION 3.16.3)
project(MultiThreading VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(MultiThreading
    # src/main.cpp
    # src/mainMutex.cpp
    # src/mainTimeMutex.cpp
    # src/mainRecursiveMutex.cpp
    # src/mainRecursiveTimedMutex.cpp
    src/mainConditionalVariable.cpp
    # src/mainSharedMutex.cpp
    # src/mainAtomic.cpp
    # src/mainLockGuard.cpp
    # src/mainUniqueLock.cpp
    # src/mainNiftyLocking.cpp
    )

    # Link pthread library
target_link_libraries(MultiThreading pthread)