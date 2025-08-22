//
// Created by xin on 2025/8/20.
//
#include <random>
#include <unordered_set>
#include <print>
#include "../include/chapter-2.h"
#include "../../core/include/list.h"
/**
 * @brief 初始化一个用于测试的顺序表，包含不重复的随机整数。
 * @param length 顺序表的长度。如果 length 超过 MaxSize，将使用 MaxSize。
 * @return 初始化好的顺序表。
 */
SqList init_test_sqlist(int length) {
    SqList list;

    // 确保长度不超过最大容量
    if (length > MaxSize) {
        length = MaxSize;
    }
    list.length = length;

    // 使用 modern C++ 的随机数生成器
    std::random_device rd;
    std::default_random_engine generator(rd());
    // 随机数范围可以根据需要调整，例如 1 到 1000
    std::uniform_int_distribution<int> distribution(1, 100);

    // 使用 std::unordered_set 来保证随机数不重复
    std::unordered_set<int> unique_numbers;

    for (int i = 0; i < length; ++i) {
        int random_num;
        // 循环直到生成一个未重复的随机数
        do {
            random_num = distribution(generator);
        } while (unique_numbers.count(random_num));

        // 将不重复的随机数存入 set 和 data 数组
        list.data[i] = random_num;
        unique_numbers.insert(random_num);
    }
    return list;
}
void test_A19_01() {
    std::print("test_19_01 ...\n");
    auto list=init_test_sqlist(10);
    Traverse(list);
    int del_min{};
    A19_01(list,del_min);
    std::println("最小元素：{}",del_min);
    Traverse(list);
}
void test_A19_02() {
    std::print("test_19_02 ...\n");
    auto list=init_test_sqlist(11);
    Traverse(list);
    A19_02(list);
    Traverse(list);
}
void test_A19_03() {
    std::print("test_19_03 ...\n");
    auto list=init_test_sqlist(10);
    list.data[3]=10;
    list.data[7]=10;
    list.data[8]=10;
    list.data[9]=10;
    Traverse(list);
    A19_03(list,10);
    Traverse(list);
}
void test_A19_04() {
    std::print("test_19_04 ...\n");
    auto list=init_test_sqlist(11);
    list.data[4]=40;
    list.data[5]=30;
    list.data[8]=31;
    Traverse(list);
    A19_04(list,30,50);
    Traverse(list);
}