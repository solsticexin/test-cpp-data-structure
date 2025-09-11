#pragma once
namespace auxiliary {
    template<typename T>
    void swap(T& a,T& b){
        T temp{a};
        a=b;
        b=temp;
    }
    int max(int a,int b);   
}
