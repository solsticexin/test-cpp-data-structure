//
// Created by xin on 2025/8/20.
//
#include <iostream>
#include "../include/chapter-3.h"
#include "../../core/include/stack.h"
using namespace stack;
using namespace std;

void test_sq_stack() {
    std::cout << "test SQ_STACK ..." << std::endl;
    SqStack S;
    int result{};
    InitStack(S);
    if (isEmpty(S))
        std::cout << "初始化测试成功 && 成功判断为空." << std::endl;
    std::cout << "---------------------push---------------------------" << std::endl;
    push(S,10);
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    push(S,20);
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    push(S,30);
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    std::cout << "---------------------pop---------------------------" << std::endl;
    pop(S,result);
    std::cout << "出栈元素" << result << std::endl;
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    pop(S,result);
    std::cout << "出栈元素" << result << std::endl;
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    pop(S,result);
    std::cout << "出栈元素" << result << std::endl;
    peek(S,result);
    std::cout << "栈顶元素" << result << std::endl;
    std::cout << "测试失败pop";
    if (!pop(S,result))
        std::cout << "测试失败pop成功！！！" << std::endl;
}