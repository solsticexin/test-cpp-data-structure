//
// Created by xin on 2025/8/20.
//
#include <print>
#include "../include/chapter-3.h"
#include "../../core/include/stack.h"
using namespace stack;
using namespace std;
void test_sq_stack() {
    print("test SQ_STACK ...\n");
    SqStack S;
    int result{};
    InitStack(S);
    if (isEmpty(S))
        println("初始化测试成功 && 成功判断为空.");
    println("---------------------push---------------------------");
    push(S,10);
    peek(S,result);
    println("栈顶元素{}",result);
    push(S,20);
    peek(S,result);
    println("栈顶元素{}",result);
    push(S,30);
    peek(S,result);
    println("栈顶元素{}",result);
    println("---------------------pop---------------------------");
    pop(S,result);
    println("出栈元素{}",result);
    peek(S,result);
    println("栈顶元素{}",result);
    pop(S,result);
    println("出栈元素{}",result);
    peek(S,result);
    println("栈顶元素{}",result);
    pop(S,result);
    println("出栈元素{}",result);
    peek(S,result);
    println("栈顶元素{}",result);
    print("测试失败pop");
    if (!pop(S,result))
        print("测试失败pop成功！！！");
}