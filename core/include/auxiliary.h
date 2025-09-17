#pragma once
#include <utility> // for std::move
#include <string>
#include <vector>

namespace auxiliary {
    template<typename T>
    class option {
    private:
        T value;
        bool has_value;

    public:
        // 默认构造函数 - 创建无值的option
        option() : has_value(false) {}
        
        // 值构造函数 - 创建有值的option
        option(T val) : value(std::move(val)), has_value(true) {}
        
        // 复制构造函数
        option(const option& other) : has_value(other.has_value) {
            if (has_value) {
                value = other.value;
            }
        }
        
        // 移动构造函数
        option(option&& other) noexcept : has_value(other.has_value) {
            if (has_value) {
                value = std::move(other.value);
                other.has_value = false;
            }
        }
        
        // 赋值运算符
        option& operator=(const option& other) {
            if (this != &other) {
                has_value = other.has_value;
                if (has_value) {
                    value = other.value;
                }
            }
            return *this;
        }
        
        // 移动赋值运算符
        option& operator=(option&& other) noexcept {
            if (this != &other) {
                has_value = other.has_value;
                if (has_value) {
                    value = std::move(other.value);
                    other.has_value = false;
                }
            }
            return *this;
        }
        
        // 检查是否有值
        bool hasValue() const {
            return has_value;
        }
        
        // 获取值（如果有）
        T& get() {
            return value;
        }
        
        const T& get() const {
            return value;
        }
        
        // 解引用操作符
        T& operator*() {
            return value;
        }
        
        const T& operator*() const {
            return value;
        }
        
        // 箭头操作符
        T* operator->() {
            return &value;
        }
        
        const T* operator->() const {
            return &value;
        }
        
        // 转换为bool（用于条件检查）
        explicit operator bool() const {
            return has_value;
        }
    };
    //交换函数
    template<typename T>
    void swap(T& a, T& b) {
        T temp{a};
        a = b;
        b = temp;
    }
    
    int max(int a, int b);
    
    // 将字符串按空格分割为vector
    std::vector<std::string> splitString(const std::string& str);
}
