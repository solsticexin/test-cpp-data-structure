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
namespace link_list {
    typedef int ElemType;
    typedef struct LNode{
        ElemType data;
        struct LNode* next;
    }LNode,*LinkList ;
    bool InitList(LinkList& L);
    int length(LinkList& L);
    LNode* GetElem(LinkList& L,int i);
    LNode* LocateElem(LinkList& L,ElemType e);
    bool ListInsert(LinkList& L,int i,ElemType e);
    bool ListDelete(LinkList& L, int i,ElemType& e);
    LinkList List_HeadInsert(LinkList& L);
    LinkList List_TailInsert(LinkList& L);
    void Traverse(LinkList& L);
}
#endif //TEST_CPP_DATASTRUCTURE_LIST_H