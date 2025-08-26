//
// Created by xin on 2025/8/20.
//
#include <iostream>
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


bool A19_05(SqList& L){
    if (L.length == 0) {
        return false;
    }
    int i{},j{1};
    for (; j< L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i+1;
    return true;
}

SqList A19_06(SqList &L1, SqList &L2){
    SqList new_L{};
    int i{},j{},k{};
    while(i<L1.length && j <L2.length){
        if (L1.data[i] <= L2.data[j]) {
            new_L.data[k] = L1.data[i];
            i++;
            k++;
        }else {
            new_L.data[k] = L2.data[j];
            j++;
            k++;
        }
    }
    if (i < L1.length) {
        new_L.data[k] =L1.data[i];
        i++;
        k++;
    }
    if (j < L2.length) {
        new_L.data[k] =L1.data[j];
        j++;
        k++;
    }
    new_L.length=k;
    return new_L; 
}

/* **********************************************************************
 * **********************************************************************
 * **********************************************************************
 * **********************************************************************
*/



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

void test_A19_06(){
    std::print("test_19_06 ...\n");
    SqList list1{};
    list1.length=3;
    list1.data[0] = 0;
    list1.data[1] = 2;
    list1.data[2] = 20;
    Traverse(list1);
    SqList list2{};
    list2.length=3;
    list2.data[0] = 1;
    list2.data[1] = 3;
    list2.data[2] = 5; 
    Traverse(list2);
    auto lsit3{A19_06(list1, list2)};
    Traverse(lsit3);
}

void test_A19_07(){
    std::print("test_19_07 ...\n");
    //设计思想先整体逆转在局部逆转
    int m=5;
    int n=7;
    int all[m+n];
    for(int i{};i<m+n;i++){
        all[i] =i;
    }
    for (int t : all) {
        std::print("{} ",t);
    }
    std::cout << "\n";
    for (int i; i < (m+n)/2; i++) {
        int temp{};
        temp=all[i];
        all[i]=all[m+n-i-1];
        all[m+n-i-1]=temp;
    }
    for (int t : all) {
        std::print("{} ",t);
    }
    std::cout << "\n";
    for (int i; i < m/2; i++) {
        int temp{};
        temp=all[i];
        all[i]=all[m-i-1];
        all[m-i-1]=temp;
    }
    for (int t : all) {
        std::print("{} ",t);
    }
    std::cout << "\n";
    int i{m},j{m+n-1};
    while (i<=j) {
        int temp{all[i]};
        all[i]=all[j];
        all[j] = temp;
        i++;
        j--;
    }
    for (int t : all) {
        std::print("{} ",t);
    }
    std::cout << "\n";
}