//
// Created by xin on 2025/8/20.
//

#include "../include/list.h"
#include <print>
bool A19_01(SqList &l, int &e) {
    if (l.length==0) return false;
    int min{l.data[0]};
    int index{};
    for (int i{1};i<l.length;i++) {
        if (l.data[i] < min) {
            min = l.data[i];
            index = i;
        }
    }
    l.data[index]=l.data[l.length-1];
    e = min;
    l.length--;
    return true;
}

void A19_02(SqList& l) {
    for (int i{0};i<l.length/2;i++) {
        int temp{};
        temp = l.data[i];
        l.data[i] = l.data[l.length-1-i];
        l.data[l.length-1-i] = temp;
    }
}

/*
 *采取双指针(一个指针顺序读取顺序表，一个指针为不相同x的个数)，判断条件为不相同时进行操作。19_04也是同理。
 *（判断条件改为相同时，指针改为相同x的个数）
 *判定条件则是
 *  if(l.data[i] == x)
 *    count++;
 *  else
 *    l.data[i-count]=l.data[i];
 */
void A19_03(SqList& l,const int x) {
    int count{0};
    for (int i{0};i<l.length;i++) {
        if (l.data[i] != x) {
            l.data[count++] = l.data[i];
        }
    }
    l.length=count;
}

bool A19_04(SqList& l,int s,int t) {
    if (s>=t || l.length ==0) return false;
    int count{};
    for (int i{0};i<l.length;i++) {
        if (l.data[i]<s ||l.data[i]>t) {
            l.data[count++] = l.data[i];
        }
    }
    l.length=count;
    return true;
}
void Traverse(SqList& l) {
    if (l.length==0) return;
    std::print("当前list:[");
    for (int i{0};i<l.length;i++) {
        if (i==l.length-1) std::print("{}",l.data[i]);
        else std::print("{},", l.data[i]);
    }
    std::print("]\n");
}