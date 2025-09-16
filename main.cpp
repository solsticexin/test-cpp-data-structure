// #include "chapter-2/include/chapter-2.h"
// #include "chapter-3/include/chapter-3.h"
// #include "core/include/string.h"
// #include "chapter-2/include/link.h"
// #include "list.h"
#include "stack.h"
#include <iostream>

void test_bracket_check();
int main() {
    test_bracket_check();
    return 0;
}
void test_bracket_check(){
    std::cout <<"测试括号匹配问题" <<std::endl;
    char test_bracket[] = "(+++123)()()";
    auto result=stack::BracketCheck(test_bracket,sizeof(test_bracket)-1);
    if(result)
        std::cout<<"匹配成功！！！\n";
    else
        std::cout<<"匹配失败！！！\n";
}