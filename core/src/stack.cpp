//
// Created by xin on 2025/8/20.
//

#include "../include/stack.h"
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

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

    bool BracketCheck(std::string str){
        auto stack{std::vector<char>()};
        for(auto c:str){
            if (c== '(' || c=='[' || c== '{') {
                stack.push_back(c);
            }else {
                if (c==')' || c==']' || c=='}') {
                    if (stack.empty()) {
                        return false;
                    }
                    auto elem_top{ stack.back()};
                    stack.pop_back();
                    if (c==')' && elem_top!='(') return false;
                    if (c==']' && elem_top!='[') return false;
                    if (c=='}' && elem_top!='{') return false;
                }
            }
        }
        return stack.empty();
    }
    int getPrecedence(char op){
        static const std::map<char,int>precedence_map{
            {'+',1},
            {'-',1},
            {'*',2},
            {'/',2}
        };
        //find是迭代器
        //end() 是一个特殊的迭代器，它指向 map 中最后一个元素的后一个位置。
        // 它不指向任何实际的元素。
        auto it=precedence_map.find(op);
        if(it!=precedence_map.end()){
            return it->second; //map包含两个成员 map(first,second)
        }
        return 0;
    }
    std::string infixToPostfix(std::string infix){
        auto check=BracketCheck(infix);
        if (!check)
            std::cout << "表达式有问题:括号不匹配\n";
        std::stack<char> opStack{};
        auto postfix{std::string()};

        for (char c : infix) {
            if (std::isalnum(c)) {
                postfix +=c;
            }else if (c=='(') {
                opStack.push(c);
            }else if (c==')') {
                while (!opStack.empty() && opStack.top()!='(') {
                    postfix += opStack.top();
                    opStack.pop();

                }
                if (!opStack.empty()) {
                    opStack.pop();
                }
            }else {
             while (!opStack.empty() &&opStack.top()!='('&&
                getPrecedence(opStack.top())>=getPrecedence(c)
                ) {
                postfix +=opStack.top();
                opStack.pop();
             }
             opStack.push(c);
            }
        }


        while (!opStack.empty()) {
            postfix +=opStack.top();
            opStack.pop();
        }
        return postfix;
    }
}
