// 题目1：constexpr变量的基本使用
// 1.声明一个constexpr整型变量并初始化。
// 2.使用该constexpr变量作为数组的大小。
// #include <iostream>
// #include <array>

// int main() {
//     constexpr int n = 10;
//     std::array<int, n> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << "\n";
// }

// 题目2：constexpr函数的使用
// 1.编写一个constexpr函数，该函数接收两个整数参数并返回它们的和。
// 2.在main函数中调用该constexpr函数，并使用其返回值作为另一个数组的大小。
#include <iostream>
#include <array>

constexpr int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr int res = add(1, 2);
    std::array<int, res> arr = {1, 2, 3};
    for (int i = 0; i < res; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}