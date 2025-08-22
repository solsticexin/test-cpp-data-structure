#构建静态库，包含list和stack的实现
add_library(
        core STATIC
        src/list.cpp
        src/stack.cpp
)

#设置头文件目录
target_include_directories(core
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)