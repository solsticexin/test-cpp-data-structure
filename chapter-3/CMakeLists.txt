#构建静态库
add_library(
        chapter-3 STATIC
        src/chapter-3.cpp
)

#设置头文件目录
target_include_directories(chapter-3
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        #引用核心库的头文件
        "${CMAKE_SOURCE_DIR}/core/include"
)

# 链接core库
target_link_libraries(chapter-3
        PUBLIC
        core
)