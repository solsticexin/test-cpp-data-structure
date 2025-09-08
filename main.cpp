#include "chapter-2/include/chapter-2.h"
#include "chapter-3/include/chapter-3.h"
#include "core/include/string.h"
#include "chapter-2/include/link.h"
#include "list.h"


int main() {
    link_list::test_ostream();
    test_A19_01();
    test_A19_02();
    test_A19_03();
    test_A19_04();
    test_sq_stack();
    test_A19_06();
    ::string::test_Index();  // 使用全局命名空间中的string
    test_A19_12();
    link_list::test_Reverse();
    
    return 0;
}