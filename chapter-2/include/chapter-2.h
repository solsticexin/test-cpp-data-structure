//
// Created by xin on 2025/8/20.
//

#ifndef TEST_CPP_DATASTRUCTURE_CHAPTER_2_H
#define TEST_CPP_DATASTRUCTURE_CHAPTER_2_H
#include <cstdlib>
using ElemType = int;
#include "../../core/include/list.h"
bool A19_05(SqList& L);
SqList A19_06(SqList& L1,SqList& L2);
void SearchExchangeInsert(ElemType A[],ElemType x);
void samekey(int A[],int B[] ,int C[],int n);
void Reverse(int* R,int from,int to);
void Converse(int R[],int n,int p);
int M_Search(int A[],int B[],int n);
int Majority(int A[],int n);
int findMissMin(int A[],int n);
int findMinofTrip(int A[],int n ,int B[],int m,int C[],int p);

void test_A19_01();
void test_A19_02();
void test_A19_03();
void test_A19_04();
void test_A19_06();
void test_A19_07();
void test_A19_12();
#endif //TEST_CPP_DATASTRUCTURE_CHAPTER_2_H;