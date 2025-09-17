//
// Created by xin on 2025/8/20.
//

#include "../include/stack.h"
#include "auxiliary.h"

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <sstream>
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
        
        // 移除所有空格以便处理
        infix.erase(std::remove(infix.begin(), infix.end(), ' '), infix.end());
        
        size_t i = 0;
        while (i < infix.length()) {
            char c = infix[i];
            
            // 处理操作数（数字、小数、负数）
            if (std::isdigit(c) || (c == '-' && (i == 0 || infix[i-1] == '(' || 
                std::string("+-*/").find(infix[i-1]) != std::string::npos))) {
                
                // 提取完整的操作数（可能包含小数点和负号）
                std::string operand;
                if (c == '-') {
                    operand += c;
                    i++;
                }
                
                while (i < infix.length() && (std::isdigit(infix[i]) || infix[i] == '.')) {
                    operand += infix[i];
                    i++;
                }
                
                // 添加到后缀表达式，并添加空格分隔符
                if (!postfix.empty() && postfix.back() != ' ') {
                    postfix += ' ';
                }
                postfix += operand;
                continue;
            }
            else if (c == '(') {
                opStack.push(c);
                i++;
            }
            else if (c == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    if (!postfix.empty() && postfix.back() != ' ') {
                        postfix += ' ';
                    }
                    postfix += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty() && opStack.top() == '(') {
                    opStack.pop();
                }
                i++;
            }
            else if (std::string("+-*/").find(c) != std::string::npos) {
                while (!opStack.empty() && opStack.top() != '(' &&
                       getPrecedence(opStack.top()) >= getPrecedence(c)) {
                    if (!postfix.empty() && postfix.back() != ' ') {
                        postfix += ' ';
                    }
                    postfix += opStack.top();
                    opStack.pop();
                }
                opStack.push(c);
                i++;
            }
            else {
                // 跳过其他字符（如空格）
                i++;
            }
        }

        while (!opStack.empty()) {
            if (!postfix.empty() && postfix.back() != ' ') {
                postfix += ' ';
            }
            postfix += opStack.top();
            opStack.pop();
        }
        
        return postfix;
    }
    /*辅助函数isOperand判断字符内型:操作数*/
    bool isOperand(std::string token){
        if(token.empty()) return false;
        size_t start_pos = 0;
        bool has_decimal_point = false;
        
        // 检查是否为负数
        if (token[0] == '-') {
            if (token.length() == 1) { // 如果字符串只有"-"
                return false;
            }
            start_pos = 1;
        }
        
        // 检查每个字符是否为数字或小数点
        for (size_t i = start_pos; i < token.length(); i++) {
            if (token[i] == '.') {
                if (has_decimal_point) {
                    return false; // 不能有多个小数点
                }
                has_decimal_point = true;
            } else if (!std::isdigit(token[i])) {
                return false; // 非数字字符
            }
        }
        
        // 不能以小数点开头或结尾
        if (token.find('.') == start_pos || token.back() == '.') {
            return false;
        }
        
        return true;
    }
    /*辅助函数isOperator判断字符内型：运算符*/
    bool isOperator(std::string token){
        return token.length()==1 && (token=="+" ||token=="-" || token=="*" ||token=="/");
    }
    //辅助函数判断是否一个有效的算术表达式，并不能判断中缀后缀前缀表达式
    /*
    思想：
        count=0 代表栈所有元素。
        采用模拟栈的结果如果是一个后缀表达式，遇见操作数入栈即count+1，
        遇见一个运算符就要出栈两个操作数，进行计算后在入栈计算结果即 -1-1+1=-1
        也是就遇见一个运算符，栈的净元素-1；
        如果是一个有效的后缀表达式，最后栈的元素只会有一个最终的计算结果。即count=1；
    */
    bool checkOperandOperatorRatio(std::string expression){
        std::stringstream ss(expression);
        std::string token{};
        int count{0};
        while (ss >> token) {
            if (isOperand(token)) {
                count++;
            }else if (isOperator(token)) {
                count--;
            }else {
                return false; //既不是操作数也不是运算符，表达式有误；
            }
        }
        return count==1;
    }
    auxiliary::option<double> Calculate(std::string postfix){
        if (!checkOperandOperatorRatio(postfix)) {
            return auxiliary::option<double>();
        }
        std::stringstream ss(postfix);
        std::string token{};
        std::stack<double> s;
        while (ss >> token) {
            if(isOperand(token)) s.push(std::stod(token));
            else if (isOperator(token)){
                if (s.size()<2) {
                    return auxiliary::option<double>();
                }
                double operand2=s.top();s.pop();
                double operand1=s.top();s.pop();
                if (token=="+") s.push(operand1+operand2);
                else if (token=="-") s.push(operand1-operand2);
                else if (token=="*") s.push(operand1*operand2);
                else if (token=="/"){
                    if (operand2==0) {
                        return auxiliary::option<double>();
                    }
                    s.push(operand1/operand2);
                } 
            }
        }
        auto result{s.top()};
        s.pop();
        return auxiliary::option<double>(result);
    }
}
