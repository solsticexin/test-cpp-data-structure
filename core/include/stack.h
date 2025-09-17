//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_STACK_H
#define TEST_CPP_DATASTRUCTURE_STACK_H
#include "auxiliary.h"
#include <string>
#ifndef STACK_MAX_SIZE
#define STACK_MAX_SIZE 100
#endif
namespace stack{
    template<typename T>    
    struct SqStack{
        T data[STACK_MAX_SIZE]{};
        int top;
    };
    template<typename T>
    void InitStack(SqStack<T>& S){
        S.top = 0;
    }
    template<typename T>
    bool StackEmpty(SqStack<T>& S){
        return S.top == 0;
    }
    template<typename T>
    bool Push(SqStack<T>& S,int e){
        if (S.top ==STACK_MAX_SIZE) {
            return false;
        }
        S.data[S.top] =e;
        S.top += 1;
        return true;
    }
    template<typename T>
    bool Pop(SqStack<T>& S,T& e){
        if (StackEmpty(S)) {
            return false;        
        }
        e=S.data[--S.top];
        return true;
    }
    template<typename T>
    bool GetTop(SqStack<T>& S,T& e){
        if (StackEmpty(S)) {
            return false;
        }
        e=S.data[S.top-1];
        return true;
    }
    //括号匹配检测
    bool BracketCheck(char str[],int length);
    bool BracketCheck(std::string str);
    //中缀转后缀表达式 字符串以空格分离 仅支持四则运算 支持符号小数，负数
    std::string infixToPostfix(std::string infix);
    //辅助函数判断是否一个有效的算术表达式，并不能判断中缀后缀前缀表达式;
    bool checkOperandOperatorRatio(std::string expression);
    //计算表达式，参数为后缀表达式。
    auxiliary::option<double> Calculate(std::string postfix);
}

#endif //TEST_CPP_DATASTRUCTURE_STACK_H
