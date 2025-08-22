//
// Created by xin on 2025/8/20.
//

#include "../include/stack.h"

namespace stack{
    void InitStack(SqStack& S) {
        S.top = 0;
    }
    bool isEmpty(SqStack& S) {
        return S.top == 0;
    }
    bool push(SqStack& S,int e) {
        if (S.top == MaxSize)
            return false;
        S.data[S.top++] = e;
        return true;
    }
    bool pop(SqStack& S,int& e) {
        if (isEmpty(S))
            return false;
        e=S.data[--S.top];
        return true;
    }
    bool peek(SqStack& S,int& e) {
        if (isEmpty(S))
            return false;
        const auto temp=S.top-1;
        e=S.data[temp];
        return true;
    }
}
