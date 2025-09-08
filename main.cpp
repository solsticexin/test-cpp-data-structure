#include "chapter-2/include/chapter-2.h"
#include "chapter-3/include/chapter-3.h"
#include "core/include/string.h"
#include "core/include/list.h"
#include "chapter-2/include/link.h"
int main() {
    test_A19_01();
    test_A19_02();
    test_A19_03();
    test_A19_04();
    test_sq_stack();
    test_A19_06();
    string::test_Index();
    test_A19_12();
    // link_list::LNode* L;
    // link_list::List_TailInsert(L);
    // link_list::Traverse(L);
    link_list::test_Reverse();
}