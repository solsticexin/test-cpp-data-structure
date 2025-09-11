//线性表的链表
#ifndef TEST_CPP_DATA_STRUCTURE_LINK_H
#define TEST_CPP_DATA_STRUCTURE_LINK_H
#include "../../core/include/list.h"
namespace link_list{
    LinkList Reverse_1(LinkList L);
    LinkList Reverse_2(LinkList L);
    void RangeDelete(LinkList& L,int min,int max);
    void test_Reverse();
    LinkList DisCreat_2(LinkList& A);
    void Del_Same(LinkList& L);
    void Get_common(LinkList& A,LinkList B); //有序递增
    LinkList Union(LinkList& la,LinkList& lb); //递增有序
    int Pattern(LinkList A,LinkList B);
    int Symmetry(DLinkList& L);
    LinkList Link(LinkList& h1,LinkList& h2);
    LNode* Converse(LNode* L,int k); //不带头结点
    LNode* FindLoopStart(LNode* head);
    int PairSum(LinkList& L);//长度为偶数，不带头结点，值大于0
    //十七题
    namespace p59_17 {
        //带头节点的单链表
        template<typename ElemType>
        struct LNode {
            ElemType data;
            struct LNode* link;
        };
        template<typename ElemType>
        using LinkList=LNode<ElemType>*;

        template<typename ElemType>
        int Search_k(LinkList<ElemType> list,int k) {
            LNode<ElemType>* p{list->link},*q{list->link};
            int count=0;
            while (p!=nullptr) {
                if (count<k) count++;
                else q=q->link;
                p=p->link;
            }
            if (count<k) return 0;
            else {
                std::cout << q->data <<std::endl;
                return 1;
            }
        }
    }
    namespace p18 {
        typedef struct Node {
            char data;
            struct Node* next;
        }SNode;
        int listlen(SNode* head);
        SNode* find_list(SNode* str1,SNode* str2);
    }
    namespace circular_linked_list {;
        typedef struct DNode {
            int data;
            DNode* next;
            DNode* pre;
            int freq; //访问频度
        }*DLinkList,DNode;
        DNode* Locate(DLinkList& L,int x);
    }
}

namespace p59_19{
    typedef struct node {
        int data;
        struct node * link;
    }NODE;
    typedef NODE* PNODE;
    void func(PNODE h,int n);
}
namespace p60_20 {
    typedef struct node {
        int data;
        node* next;
    }NODE;
    void change_list(NODE* h);
}
#endif