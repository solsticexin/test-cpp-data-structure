#include "../include/link.h"
#include <iostream>
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
}