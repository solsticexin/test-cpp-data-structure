//
// Created by xin on 2025/8/20.
//

#include "../include/stack.h"

namespace stack{
    // void InitStack(SqStack& S) {
    //     S.top = 0;
    // }
    // bool StackEmpty(SqStack& S) {
    //     return S.top == 0;
    // }
    // bool Push(SqStack& S,int e) {
    //     if (S.top == MaxSize)
    //         return false;
    //     S.data[S.top++] = e;
    //     return true;
    // }
    // bool Pop(SqStack& S,int& e) {
    //     if (StackEmpty(S))
    //         return false;
    //     e=S.data[--S.top];
    //     return true;
    // }
    // bool GetTop(SqStack& S,int& e) {
    //     if (StackEmpty(S))
    //         return false;
    //     const auto temp=S.top-1;
    //     e=S.data[temp];
    //     return true;
    // }
    bool BracketCheck(char str[],int length){
        SqStack<char> S;
        InitStack(S);
        for(int i{};i<length;i++){
            if (str[i] == '(' ||str[i] == '[' || str[i] == '{'){
                Push(S,str[i]);
            }else{
                if(str[i]==')' || str[i]== ']' || str[i]=='}'){
                    if(StackEmpty(S)){
                        return false;
                    }
                    char elem_top{};
                    Pop(S,elem_top);
                    if (str[i]==')' && elem_top !='(') {
                        return false;
                    }
                    if (str[i]==']' && elem_top !='[') {
                        return false;
                    }
                    if (str[i]=='}' && elem_top !='{') {
                        return false;
                    }
                }
            }
        }
        return StackEmpty(S);
    }
}
