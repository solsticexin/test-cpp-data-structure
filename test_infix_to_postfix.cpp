#include <iostream>
#include "core/include/stack.h"

int main() {
    // 测试基本四则运算
    std::cout << "测试基本四则运算:" << std::endl;
    std::string expr1 = "3 + 4 * 2";
    std::string postfix1 = stack::infixToPostfix(expr1);
    std::cout << "中缀: " << expr1 << " -> 后缀: " << postfix1 << std::endl;
    
    auto result1 = stack::Calculate(postfix1);
    if (result1.hasValue()) {
        std::cout << "计算结果: " << result1.get() << std::endl;
    } else {
        std::cout << "计算失败" << std::endl;
    }
    std::cout << std::endl;

    // 测试小数
    std::cout << "测试小数:" << std::endl;
    std::string expr2 = "3.5 + 2.1 * 4.2";
    std::string postfix2 = stack::infixToPostfix(expr2);
    std::cout << "中缀: " << expr2 << " -> 后缀: " << postfix2 << std::endl;
    
    auto result2 = stack::Calculate(postfix2);
    if (result2.hasValue()) {
        std::cout << "计算结果: " << result2.get() << std::endl;
    } else {
        std::cout << "计算失败" << std::endl;
    }
    std::cout << std::endl;

    // 测试负数
    std::cout << "测试负数:" << std::endl;
    std::string expr3 = "-5 + 3 * -2";
    std::string postfix3 = stack::infixToPostfix(expr3);
    std::cout << "中缀: " << expr3 << " -> 后缀: " << postfix3 << std::endl;
    
    auto result3 = stack::Calculate(postfix3);
    if (result3.hasValue()) {
        std::cout << "计算结果: " << result3.get() << std::endl;
    } else {
        std::cout << "计算失败" << std::endl;
    }
    std::cout << std::endl;

    // 测试混合小数和负数
    std::cout << "测试混合小数和负数:" << std::endl;
    std::string expr4 = "-3.5 * 2.1 + 4.7 / -2.0";
    std::string postfix4 = stack::infixToPostfix(expr4);
    std::cout << "中缀: " << expr4 << " -> 后缀: " << postfix4 << std::endl;
    
    auto result4 = stack::Calculate(postfix4);
    if (result4.hasValue()) {
        std::cout << "计算结果: " << result4.get() << std::endl;
    } else {
        std::cout << "计算失败" << std::endl;
    }
    std::cout << std::endl;

    // 测试带括号的表达式
    std::cout << "测试带括号的表达式:" << std::endl;
    std::string expr5 = "(-3.5 + 2.1) * (4.7 - 2.0)";
    std::string postfix5 = stack::infixToPostfix(expr5);
    std::cout << "中缀: " << expr5 << " -> 后缀: " << postfix5 << std::endl;
    
    auto result5 = stack::Calculate(postfix5);
    if (result5.hasValue()) {
        std::cout << "计算结果: " << result5.get() << std::endl;
    } else {
        std::cout << "计算失败" << std::endl;
    }

    return 0;
}
