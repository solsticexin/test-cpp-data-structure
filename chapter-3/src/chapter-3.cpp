//
// Created by xin on 2025/8/20.
//
#include <iostream>
#include "../include/chapter-3.h"
// #include <cstdlib>
#include "../../core/include/stack.h"
using namespace stack;
using namespace std;

void test_sq_stack() {
    std::cout << "test SQ_STACK ..." << std::endl;
    SqStack S;
    int result{};
    InitStack(S);
    if (StackEmpty(S))
        std::cout << "初始化测试成功 && 成功判断为空." << std::endl;
    std::cout << "---------------------push---------------------------"
              << std::endl;
    Push(S, 10);
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    Push(S, 20);
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    Push(S, 30);
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    std::cout << "---------------------pop---------------------------"
              << std::endl;
    Pop(S, result);
    std::cout << "出栈元素" << result << std::endl;
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    Pop(S, result);
    std::cout << "出栈元素" << result << std::endl;
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    Pop(S, result);
    std::cout << "出栈元素" << result << std::endl;
    GetTop(S, result);
    std::cout << "栈顶元素" << result << std::endl;
    std::cout << "测试失败pop";
    if (!Pop(S, result)) std::cout << "测试失败pop成功！！！" << std::endl;
}

bool Judage(char A[]) {
    int i{};
    int j{},k{};
    while (A[i] != '\0') {
        switch (A[i]) {
            case 'I': j++; break;
            case 'O': k++;
            if(k>j){std::cout<<"序列非法\n";exit(0);}
        }
        i++;
    }
    if(j != k){
        std::cout << "序列非法\n";
        return false;
    }else {
        std::cout << "序列合法\n";
        return true;
    }
}