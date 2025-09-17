cmake_minimum_required(VERSION 4.0)
project(test_cpp_DataStructure)

set(CMAKE_CXX_STANDARD 17)

# Core library
add_library(
    core STATIC
    core/src/list.cpp
    core/src/stack.cpp
    core/src/string.cpp
    core/src/auxiliary.cpp
)

target_include_directories(core
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/core/include"
)

# Chapter-2 library
add_library(
    chapter-2 STATIC
    chapter-2/src/chapter-2.cpp
    chapter-2/src/link.cpp
)

target_include_directories(chapter-2
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/chapter-2/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/include"
)

target_link_libraries(chapter-2
    PUBLIC
    core
)

# Chapter-3 library
add_library(
    chapter-3 STATIC
    chapter-3/src/chapter-3.cpp
)

target_include_directories(chapter-3
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/chapter-3/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/include"
)

target_link_libraries(chapter-3
    PUBLIC
    core
)

# Executable
add_executable(
    test_cpp_DataStructure 
    main.cpp        
)

target_link_libraries(test_cpp_DataStructure
    PUBLIC
    core
    chapter-2
    chapter-3
)
