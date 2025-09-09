#include "../include/link.h"
#include "list.h"
#include <iostream>
#include <bits/stl_set.h>

namespace link_list{
    LinkList Reverse_1(LinkList L){
        LNode* p,*rear;
        p=L->next;
        L->next=nullptr;
        while(p!=nullptr){
            rear=p->next;
            p->next=L->next;
            L->next=p;
            p=rear;
        }
        return L;
    }
    LinkList Reverse_2(LinkList L){
        LNode* pre,* p=L->next,* rear=p->next;
        p->next=nullptr;
        while(rear!=nullptr){
            pre=p;
            p=rear;
            rear=rear->next;
            p->next=pre;
        }
        L->next=p;
        return L;
    }
    void test_Reverse(){
        // 创建测试链表
        LinkList list1, list2;
        InitList(list1);
        InitList(list2);
        
        // 创建一些测试数据
        for (int i = 1; i <= 5; i++) {
            ListInsert(list1, i, i * 10);
            ListInsert(list2, i, i * 10);
        }
        
        std::cout << "原始链表: ";
        Traverse(list1);
        
        // 测试 Reverse_1
        std::cout << "Reverse_1 逆置后: ";
        auto result_1=Reverse_1(list1);
        Traverse(result_1);
        
        // // 重新初始化list2为原始状态
        // for (int i = 1; i <= 5; i++) {
        //     ListInsert(list2, i, i * 10);
        // }
        
        // 测试 Reverse_2
        std::cout << "Reverse_2 逆置后: ";
        auto result_2=Reverse_2(list2);
        Traverse(result_2);
        
        // 清理内存
        // 注意：这里为了简化测试，没有进行内存释放
    }
    void RangeDelete(LinkList& L,int min,int max){
        LNode* pre=L,*p=L->next;
        while(p!=nullptr){
            if(p->data>min && p->data<max){
                pre->next=p->next;
                delete p;
                p=pre->next;
            }else{
                pre=p;
                p=p->next;
            }
        }
    }
    /**
     * 将链表A拆分为两个链表A和B，采用交替取元素的方式
     * 将原链表中的第1,3,5,...个元素保留在链表A中
     * 将原链表中的第2,4,6,...个元素放入新链表B中
     * @param A 输入的链表，拆分后保留奇数位置的元素
     * @return 新创建的链表B，包含原链表中偶数位置的元素
     */
    LinkList DisCreat_2(LinkList& A){
        const auto B=new LNode();
        B->next=nullptr;
        LNode* p=A->next,*q;
        LNode* ra=A;
        while (p!=nullptr) {
            // 取一个节点放入链表A中
            ra->next=p;
            ra=p;
            p=p->next;
            // 如果还有节点，则取下一个节点放入链表B中
            if (p!=nullptr) {
                q=p->next;
                p->next=B->next;
                B->next=p;
                p=q;
            }
        }
        ra->next=nullptr;
        return B;
    }
    void Del_Same(LinkList& L){
        if(L==nullptr)return;
        auto p=L->next;
        LNode* q{nullptr};
        while (p!=nullptr && p->next!=nullptr) {
            if (p->data==p->next->data) {
                q=p->next;
                p->next=q->next;
                delete  q;
            }else {
                p=p->next;
            }
        }
    }
    void Get_common(LinkList& A,LinkList B){
        LNode* p=A->next,*q=B->next,*r,*s;
        const auto C=new LNode();
        r=C;
        while(p!=nullptr&&q!=nullptr){
            if (p->data < q->data) {
                p=p->next;
            }else if (p->data > q->data) {
                q=q->next;
            }else {
                s=new LNode();
                s->data=p->data;
                r->next=s;
                r=s;
                p=p->next;
                q=q->next;
            }
        }
        r->next=nullptr;
    }
    LinkList Union(LinkList& la,LinkList& lb){
        LNode* p=la->next;
        LNode* q=lb->next;
        LNode* pc =la;
        LNode* temp;
        while(p!=nullptr && q!=nullptr){
            if (p->data ==q->data) {
                pc->next=p;
                pc=p;
                temp=q;
                q=q->next;
                p=p->next;
                delete temp;
            }else if(p->data <q->data){
                temp=p;
                p=p->next;
                delete temp;
            }else {
                temp=q;
                q=q->next;
                delete temp;
            }
        }
        while (p) {
            temp=p;
            p=p->next;
            delete temp;
        }
        while (q) {
            temp=q;
            q=q->next;
            delete temp;
        }
        pc->next=nullptr;
        delete lb;
        return la;
    }
    int Pattern(LinkList A,LinkList B){
        LNode* p=A;
        LNode* pre=p;
        LNode* q=B;
        while (p&&q) {
            if (p->data == q->data) {
                p=p->next;
                q=q->next;
            }else {
                pre=pre->next;
                p=pre;
                q=B;
            }
        }
        if (q==nullptr) {
            return 1;
        }else {
            return 0;
        }
    }
    int Symmetry(DLinkList& L){
        const DNode* p=L->next;
        const DNode* q=L->prior;
        while (p!=q && p->next!=q){
            if (p->data == q->data){
                p=p->next;
                q=q->prior;
            }else
                return 0;
        }
        return 1;
    }
    LinkList Link(LinkList& h1, LinkList& h2) {
        LNode* p{},*q{};
        p=h1;
        while (p->next!=h1) {
            p=p->next;
        }
        q=h2;
        while (q->next!=h2) {
            q=q->next;
        }
        p->next=h2;
        q->next=h1;
        return h1;
    }

    namespace circular_linked_list {
    DNode* Locate(DLinkList& L, int x) {
        DNode* p{L->next},*q;
        while (p&&p->data!=x)
            p=p->next;
        if (!p) {
            exit(0);
        }else {
            (p->freq)++;
        }
        if (p->pre == L ||p->pre->freq > p->freq) {
            return p;
        }
        if (p->next !=nullptr)
            p->next->pre=p->pre;
        p->pre->next=p->next;
        q=p->pre;
        while (q!=L && q->freq <= p->freq)
            q=q->pre;
        p->next=q->next;
        if (q->next!=nullptr)
            q->next->pre=p;
        p->pre=q;
        q->next=p;
        return p;
    }
    // DNode* Locate_2(DLinkList& L,int x) {
    //     if (L==nullptr) return nullptr;
    //     DNode* p{L->next};
    //     DNode* temp{nullptr};
    //     while (p!=nullptr && p->data!=x) p=p->next; //找到x所在结点
    //     if (p==nullptr) exit(0);
    //     p->freq++;
    //     temp=p->pre;
    //     if (p->pre==L ||temp->freq > p->freq) { //判断x所在结点时候是头结点或者是前一结点是否大于x所在结点
    //         return  p;
    //     }
    //     if (p->next ==nullptr)
    // }
    }
}
