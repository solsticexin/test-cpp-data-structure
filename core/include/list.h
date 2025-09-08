//
// Created by xin on 2025/8/20.
// 描述：线性表操作头文件，包含顺序表和链表的结构定义及函数声明
//

#ifndef TEST_CPP_DATASTRUCTURE_LIST_H
#define TEST_CPP_DATASTRUCTURE_LIST_H

#include <iostream>

// 顺序表相关
#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int length;
}SqList;

// 遍历顺序表
void Traverse(SqList& l);

bool A19_01(SqList& l,int& e);
void A19_02(SqList& l);
void A19_03(SqList& l,int x);
bool A19_04(SqList& l,int s,int t);

// 链表相关命名空间
namespace link_list {
    // 元素类型定义
    typedef int ElemType;
    
    // 前向声明
    struct LNode;
    typedef struct LNode* LinkList;
    
    // 链表节点结构
    typedef struct LNode{
        ElemType data;
        struct LNode* next;
    }LNode;
    
    // 初始化链表
    bool InitList(LinkList& L);
    
    // 获取链表长度
    int length(LinkList& L);
    
    // 按位查找
    LNode* GetElem(LinkList& L,int i);
    
    // 按值查找
    LNode* LocateElem(LinkList& L,ElemType e);
    
    // 插入操作
    bool ListInsert(LinkList& L,int i,ElemType e);
    
    // 删除操作
    bool ListDelete(LinkList& L, int i,ElemType& e);
    
    // 头插法建立链表
    LinkList List_HeadInsert(LinkList& L);
    
    // 尾插法建立链表
    LinkList List_TailInsert(LinkList& L);
    
    // 遍历链表
    void Traverse(LinkList& L);
    
    // 重载<<运算符，用于打印链表
    std::ostream& operator<<(std::ostream& out, const LinkList& L);
    void test_ostream();
}

#endif //TEST_CPP_DATASTRUCTURE_LIST_H