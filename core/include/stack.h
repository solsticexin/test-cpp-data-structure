//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_STACK_H
#define TEST_CPP_DATASTRUCTURE_STACK_H

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
    bool BracketCheck(char str[],int length);
}

#endif //TEST_CPP_DATASTRUCTURE_STACK_H
