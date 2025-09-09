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
}
#endif