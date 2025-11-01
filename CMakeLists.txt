# Require at least the CMake version that is readily available in the testing
# environment so the project can still take advantage of the existing C++23 and
# module configuration when built locally.
cmake_minimum_required(VERSION 3.28.3)

# Determine whether the selected generator offers native support for C++ module
# dependency scanning. When it does, opt-in to the experimental dynamic
# dependency processing that CMake 3.28.x provides.
set(_supports_cxx_modules OFF)
if (CMAKE_GENERATOR MATCHES "Ninja" OR CMAKE_GENERATOR MATCHES "Visual Studio")
    set(_supports_cxx_modules ON)
endif()

if (_supports_cxx_modules)
    # Must be set before the first project() call.
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
endif()

project(test_cpp_DataStructure)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (_supports_cxx_modules)
    set(CMAKE_CXX_SCAN_FOR_MODULES ON)
else()
    set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
endif()

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

target_compile_features(core PUBLIC cxx_std_23)

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

target_compile_features(chapter-2 PUBLIC cxx_std_23)

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

target_compile_features(chapter-3 PUBLIC cxx_std_23)

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

target_compile_features(test_cpp_DataStructure PUBLIC cxx_std_23)
