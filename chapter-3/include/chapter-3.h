//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_CHAPTER_3_H
#define TEST_CPP_DATASTRUCTURE_CHAPTER_3_H
// #include <stack>
typedef struct LNode{
    char data;
    LNode* next;
}LNode,*LinkList;

void test_sq_stack();
bool Judage(char A[]);
int dc(LinkList L,int n);
#define maxsize 100
#define elemtp int 
typedef struct{
    elemtp stack[maxsize];
    int top[2];
}stk;
stk s;
int push(int i ,elemtp x);
elemtp pop(int i);
#endif //TEST_CPP_DATASTRUCTURE_CHAPTER_3_H