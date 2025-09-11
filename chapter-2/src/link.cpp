#include "../include/link.h"
#include "list.h"
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
    LNode* Converse(LNode* L, int k) {
        int n{1};
        LNode* p{L};
        while (p->next!=nullptr) {
            p=p->next;
            n++;
        }
        p->next =L;
        for (int i{1};i<n-k;i++) {
            p=p->next;
        }
        L=p->next;
        p->next=nullptr;
        return L;
    }
    LNode* FindLoopStart(LNode* head) {
        LNode* fast{head},*slow{head};
        while (fast!=nullptr&& fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        if (fast==nullptr || fast->next ==nullptr) return nullptr;
        LNode* p1=head;
        LNode* p2 {slow};
        while (p1!=p2) {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
    int PairSum(LinkList& L) {
        LNode* fast=L->next,*slow{L};
        while (fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        LNode* newHead{nullptr},*p=slow->next,*tmp{};
        while (p!=nullptr) {
            tmp=p->next;
            p->next=newHead;
            newHead=p;
            p=tmp;
        }
        int mx{0};
        p=L;
        LNode* q{newHead};
        while (q!=nullptr) {
            if (p->data + q->data >mx)
                mx=p->data+q->data;
            p=p->next;
            q=q->next;
        }
        return mx;
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
    }
    namespace p18 {
        int listlen(SNode* head) {
            int len{};
            while (head->next!=nullptr) {
                len++;
                head=head->next;
            }
            return len;
        }
        SNode* find_list(SNode* str1, SNode* str2) {
            int m,n;
            SNode*p,*q;
            m=listlen(str1);
            n=listlen(str2);
            for (p=str1;m>n;m--) {
                p=p->next;
            }
            for (q=str2;m<n;n--) {
                q=q->next;
            }
            while (p->next!=nullptr&&p->next!=q->next) {
                p=p->next;
                q=q->next;
            }
            return p->next;
        }

    }
}

namespace p59_19 {
    void func(PNODE h, int n) {
        PNODE p=h,r{};
        int *q{},m{};
        q=new int[n+1]();
        for (int i{};i<n+1;i++)
            *(q+i)=0;
        while (p->link!=nullptr) {
            m=p->link->data>0? p->link->data:-p->link->data;
            if (*(q+m)==0) {
                *(q+m)=1;
                p=p->link;
            }else{}
            r=p->link;
            p->link=r->link;
            delete r;
        }
        delete[] q;
    }

}

namespace p60_20 {
    void change_list(NODE* h) {
        NODE* p,*q,*r,*s;
        p=q=h;
        while (p->next!=nullptr) {
            p=p->next;
            q=q->next;
            if (q->next!=nullptr) q=q->next;
        }
        q=q->next;
        p->next=nullptr;
        while (q!=nullptr) {
            r=q->next;
            q->next=p->next;
            p->next=q;
            q=r;
        }
        s=h->next;
        q=p->next;
        p->next=nullptr;
        while (q!=nullptr) {
            r=q->next;
            q->next=s->next;
            s->next=q;
            q=r;
        }
    }

}