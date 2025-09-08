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
}
#endif