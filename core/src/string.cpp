#include <iostream>
#include "../include/string.h"
namespace string{
    int Index(std::string S,std::string T){
        if(S.empty() || T.empty() || S.length()<T.length()) return -2;
        int i{},j{};
        while (i<S.length() && j<T.length()) {
            if (S[i] == T[j]) {
                i++;j++;
            }else {
                i=i-j+1;
                j=0;
            }
        }
        if (j>=T.length()) {
            return i-T.length();
        }else {
            return -1;
        }
    }
    void test_Index(){
            std::string S="abdasda";
            std::string T="abd";
            auto result=string::Index(S,T);
            if (result==-1) {
                std::cout<< "匹配失败！\n";
             }else
                 std::cout << "成功！\n";
    }
}