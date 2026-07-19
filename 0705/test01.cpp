// 题目1：auto 的使用
// 编写一个C++程序，定义一个函数findMax，该函数接收两个任意类型（使用模板）的参数（假设这些类型支持比较操作），
// 并使用auto关键字自动推导返回类型，返回这两个参数中的较大值。（使用C++17标准）
// 验收标准：
// 1.程序应能正确编译并运行。
// 2.findMax函数应能正确处理不同类型的参数，并返回它们中的较大值。
// 3.应使用auto关键字自动推导返回类型。
#include <iostream>
#include <string>
template<class T1, class T2>
auto findMax(T1 obj1, T2 obj2) -> decltype(obj1 > obj2 ? obj1 : obj2) {
    if (obj1 > obj2) {
        return obj1;
    } else {
        return obj2;
    }
}

int main() {
    double a = 4.5;
    int b = 45;
    std::string s1 = "banana";
    std::string s2 = "apple";
    auto res  = findMax(a, b);
    std::cout << res << "\n";
    auto ret = findMax(s1, s2);
    std::cout << ret << "\n";
}