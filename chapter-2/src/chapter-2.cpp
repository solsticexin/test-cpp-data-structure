//
// Created by xin on 2025/8/20.
//
#include <iostream>
#include <random>
#include <unordered_set>
#include <iostream>
#include "../include/chapter-2.h"
#include "../../core/include/list.h"
#include "../../core/include/auxiliary.h"
/**
 * @brief 初始化一个用于测试的顺序表，包含不重复的随机整数。
 * @param length 顺序表的长度。如果 length 超过 MaxSize，将使用 MaxSize。
 * @return 初始化好的顺序表。
 */
SqList init_test_sqlist(int length) {
    SqList list;

    // 确保长度不超过最大容量
    if (length > MaxSize) {
        length = MaxSize;
    }
    list.length = length;

    // 使用 modern C++ 的随机数生成器
    std::random_device rd;
    std::default_random_engine generator(rd());
    // 随机数范围可以根据需要调整，例如 1 到 1000
    std::uniform_int_distribution<int> distribution(1, 100);

    // 使用 std::unordered_set 来保证随机数不重复
    std::unordered_set<int> unique_numbers;

    for (int i = 0; i < length; ++i) {
        int random_num;
        // 循环直到生成一个未重复的随机数
        do {
            random_num = distribution(generator);
        } while (unique_numbers.count(random_num));

        // 将不重复的随机数存入 set 和 data 数组
        list.data[i] = random_num;
        unique_numbers.insert(random_num);
    }
    return list;
}


bool A19_05(SqList& L){
    if (L.length == 0) {
        return false;
    }
    int i{},j{1};
    for (; j< L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i+1;
    return true;
}

SqList A19_06(SqList &L1, SqList &L2){
    SqList new_L{};
    int i{},j{},k{};
    while(i<L1.length && j <L2.length){
        if (L1.data[i] <= L2.data[j]) {
            new_L.data[k] = L1.data[i];
            i++;
            k++;
        }else {
            new_L.data[k] = L2.data[j];
            j++;
            k++;
        }
    }
    if (i < L1.length) {
        new_L.data[k] =L1.data[i];
        i++;
        k++;
    }
    if (j < L2.length) {
        new_L.data[k] =L1.data[j];
        j++;
        k++;
    }
    new_L.length=k;
    return new_L; 
}
void SearchExchangeInsert(ElemType A[],ElemType x,int n){ //n是数组长度
    int low{},hight{n-1},mid{};
    while (low <= hight) {
        mid=(low+hight)/2;
        if (A[mid] == x) break;
        else if(A[mid]<x) low=mid+1;
        else hight=mid-1;
    }
    if (A[mid]==x && mid != n-1) {
        auxiliary::swap(A[mid],A[mid+1]);
    }
    if (low>hight) {
        int i{n-1};
        for (;i>hight; i--) {
            A[i+1] =x;
        }
        A[i+1] =x;
    }
}
void samekey(int A[],int B[] ,int C[],int n){
    int i{},j{},k{};
    while (i<n && j<n && k<n) {
        if (A[i] == B[j] == C[k]) {
            std::cout <<  A[i] << "\n";
            i++;
            j++;
            k++;
        }else {
            auto max=auxiliary::max(auxiliary::max(A[i], B[j]), C[k]);
            if(A[i] < max) i++;
            if(B[j]<max) j++;
            if(C[k] < max) k++;
        }
    }
}
void Reverse(int* R,int from,int to){
    int i{},temp{};
    for(;i<(to-from)/2;i++){
        auxiliary::swap(R[from+i], R[to-i]);
    }
}
void Converse(int R[],int n,int p){
    Reverse(R, 0, p-1);
    Reverse(R, p, n-1);
    Reverse(R, 0,n-1);
}
int M_Search(int A[],int B[],int n){
    int s1,d1,m1,s2,d2,m2;
    s1=0; d1=n-1;
    s2=0;d2=n-1;
    while (s1 !=d1 || s2 !=d2) {
        m1=(s1+d1)/2;
        m2 =(s2+d2)/2;
        if (A[m1]==B[m2]) {
            return A[m1];
        }
        if (A[m1]<B[m2]){
            if((s1+d1)%2 ==0){
                s1 =m1;
                d2 =m2;
            }else {
                s1 =m1+1;
                d2 =m2;
            }
        }else {
            if((s1+d1)% 2==0){
                d1 =m1;
                s2 =m2;
            }else{
                d1 =m1;
                s2 =m2+1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}
int Majority(int A[],int n){
    int i{},c{},count{1};
    c=A[0];
    for (i=1;i<n;i++){
        if (A[i] == c)
            count++;
        else 
            if(count>0)
                count--;
            else{
                c=A[i];
                count=1;
            }
    }
    if(count >0){
        for(i =count =0;i<n;i++)
            if(A[i] == c)
                count++;
    }
    if(count>n/2) 
        return c;
    else
        return  -1;;
}
/* **********************************************************************
 * **********************************************************************
 * **********************************************************************
 * **********************************************************************
*/



void test_A19_01() {
    std::cout << "test_19_01 ..." << std::endl;
    auto list=init_test_sqlist(10);
    Traverse(list);
    int del_min{};
    A19_01(list,del_min);
    std::cout << "最小元素：" << del_min << std::endl;
    Traverse(list);
}
void test_A19_02() {
    std::cout << "test_19_02 ..." << std::endl;
    auto list=init_test_sqlist(11);
    Traverse(list);
    A19_02(list);
    Traverse(list);
}
void test_A19_03() {
    std::cout << "test_19_03 ..." << std::endl;
    auto list=init_test_sqlist(10);
    list.data[3]=10;
    list.data[7]=10;
    list.data[8]=10;
    list.data[9]=10;
    Traverse(list);
    A19_03(list,10);
    Traverse(list);
}
void test_A19_04() {
    std::cout << "test_19_04 ..." << std::endl;
    auto list=init_test_sqlist(11);
    list.data[4]=40;
    list.data[5]=30;
    list.data[8]=31;
    Traverse(list);
    A19_04(list,30,50);
    Traverse(list);
}

void test_A19_06(){
    std::cout << "test_19_06 ..." << std::endl;
    SqList list1{};
    list1.length=3;
    list1.data[0] = 0;
    list1.data[1] = 2;
    list1.data[2] = 20;
    Traverse(list1);
    SqList list2{};
    list2.length=3;
    list2.data[0] = 1;
    list2.data[1] = 3;
    list2.data[2] = 5; 
    Traverse(list2);
    auto lsit3{A19_06(list1, list2)};
    Traverse(lsit3);
}

void test_A19_07(){
    std::cout << "test_19_07 ..." << std::endl;
    //设计思想先整体逆转在局部逆转
    int m=5;
    int n=7;
    int all[m+n];
    for(int i{};i<m+n;i++){
        all[i] =i;
    }
    for (int t : all) {
        std::cout << t << " ";
    }
    std::cout << "\n";
    for (int i; i < (m+n)/2; i++) {
        int temp{};
        temp=all[i];
        all[i]=all[m+n-i-1];
        all[m+n-i-1]=temp;
    }
    for (int t : all) {
        std::cout << t << " ";
    }
    std::cout << "\n";
    for (int i; i < m/2; i++) {
        int temp{};
        temp=all[i];
        all[i]=all[m-i-1];
        all[m-i-1]=temp;
    }
    for (int t : all) {
        std::cout << t << " ";
    }
    std::cout << "\n";
    int i{m},j{m+n-1};
    while (i<=j) {
        int temp{all[i]};
        all[i]=all[j];
        all[j] = temp;
        i++;
        j--;
    }
    for (int t : all) {
        std::cout << t << " ";
    }
    std::cout << "\n";
}