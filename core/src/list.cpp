//
// Created by xin on 2025/8/20.
//

#include "../include/list.h"
#include <iostream>
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
    std::cout << "当前list:[";
    for (int i{0};i<l.length;i++) {
        if (i==l.length-1) std::cout << l.data[i];
        else std::cout << l.data[i] << ",";
    }
    std::cout << "]" << std::endl;
}

namespace link_list {
    bool InitList(LinkList& L){
        L=new LNode;
        if (L==nullptr) {
            return false;
        }
        L->next=nullptr;
        return true;
    }
    int length(LinkList& L){
        int len{};
        LNode* p =L;
        while (p->next!=nullptr) {
            p=p->next;
            len=len+1;
        }
        return len;
    }
    LNode* GetElem(LinkList& L,int i){
        LNode* p=L;
        int j=0;
        while (p!=nullptr && j<i) {
            p=p->next;
            j++;
        }
        return p;
    }
    LNode* LocateElem(LinkList& L,ElemType e){
        LNode* p =L->next;
        while (p!=nullptr && p->data!=e) {
            p=p->next;
        }
        return p;
    }
    bool ListInsert(LinkList& L,int i,ElemType e){
        LNode* p=L;
        int j=0;
        while (j<i-1 && p!=nullptr) {
            p=p->next;
            j++;
        }
        auto new_node=new LNode();
        if (p==nullptr || new_node==nullptr) {
            return false;
        }
        new_node->data=e;
        new_node->next=p->next;
        p->next=new_node;
        return true;
    }
    bool ListDelete(LinkList& L, int i,ElemType& e){
        auto p=L;
        int j{};
        while (p!=nullptr && j<i-1) {
            p=p->next;
            j++;
        }
        if (p==nullptr||p->next==nullptr) {
            return false;
        }
        auto temp=p->next;
        e=temp->data;
        p->next=temp->next;
        delete temp;
        return true;
    }
    LinkList List_HeadInsert(LinkList& L){
        LNode* s;
        int x;
        L=new LNode();
        L->next=nullptr;
        std::cout << "输入ElemType\n";
        std::cin >> x;
        while (x!=999) {
            s=new LNode();
            s->data=x;
            s->next=L->next;
            L->next=s;
            std::cout << "输入ElemType\n";
            std::cin >>x;
        }
        return L;
    }
    LinkList List_TailInsert(LinkList& L){
        int x;
        L=new LNode();
        LNode* s,*r=L;
        std::cout << "输入ElemType\n";
        std::cin >> x;
        while (x!=999) {
            s=new LNode();
            s->data=x;
            r->next=s;
            r=s;
            std::cout << "输入ElemType\n";
            std::cin >> x;
        }
        r->next=nullptr;
        return L;
    }
    void Traverse(LinkList& L){
        LNode* p=L;
        std::cout <<"[ ";
        while (p!=nullptr && p->next!=nullptr) {
            if (p->next->next==nullptr) {
                std::cout << p->next->data;
            }else {
                std::cout << p->next->data<<",";
            }
            p=p->next;
        }
        std::cout <<" ]\n";
    }
}