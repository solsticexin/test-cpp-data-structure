//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_STACK_H
#define TEST_CPP_DATASTRUCTURE_STACK_H

#define  MaxSize 100

namespace stack{
typedef struct Stack {
        int data[MaxSize];
        int top;
    } SqStack;
    void InitStack(SqStack& S);
    bool StackEmpty(SqStack& S);
    bool Push(SqStack& S,int e);
    bool Pop(SqStack& S,int& e);
    bool GetTop(SqStack& S,int& e);
}

#endif //TEST_CPP_DATASTRUCTURE_STACK_H