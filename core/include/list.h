//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_LIST_H
#define TEST_CPP_DATASTRUCTURE_LIST_H

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int length;
}SqList;


void Traverse(SqList& l);
bool A19_01(SqList& l,int& e);
void A19_02(SqList& l);
void A19_03(SqList& l,int x);
bool A19_04(SqList& l,int s,int t);
#endif //TEST_CPP_DATASTRUCTURE_LIST_H