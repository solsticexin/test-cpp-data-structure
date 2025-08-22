cmake_minimum_required(VERSION 4.0)
project(test_cpp_DataStructure)

set(CMAKE_CXX_STANDARD 26)

#添加核心数据结构库
add_subdirectory(core)
#添加第二章模块
add_subdirectory(chapter-2)
#添加第三章模块
add_subdirectory(chapter-3)

#编译主程序
add_executable(test_cpp_DataStructure main.cpp)


#链接各个模块的库
target_link_libraries( test_cpp_DataStructure
        PUBLIC
        core
        chapter-2
        chapter-3
)