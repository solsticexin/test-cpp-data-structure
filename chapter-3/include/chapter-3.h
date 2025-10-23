//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_CHAPTER_3_H
#define TEST_CPP_DATASTRUCTURE_CHAPTER_3_H
typedef struct LNode{
    char data;
    LNode* next;
}LNode,*LinkList;

void test_sq_stack();
bool Judage(char A[]);
int dc(LinkList L,int n);
#endif //TEST_CPP_DATASTRUCTURE_CHAPTER_3_H