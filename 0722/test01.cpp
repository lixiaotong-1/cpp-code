// 题目：完美转发示例

// 要求：编写一个模板函数wrapper，该函数接收任意类型和数量的参数，
// 并将这些参数完美转发给另一个函数process。process函数有两个重载版本，
// 一个接受左值引用，另一个接受右值引用。通过调用wrapper函数，验证完美转发的正确性。

// 验收标准：
// wrapper函数能够正确地将参数转发给process函数。
// 当传递给wrapper的参数是左值时，应调用process的左值引用重载版本。
// 当传递给wrapper的参数是右值时，应调用process的右值引用重载版本。
#include <iostream>
#include <utility>

template <typename T>
void process(T& a) {
    std::cout << "left value reference" << "\n";
}

template <typename T>
void process(T&& a) {
    std::cout << "right value reference" << "\n";
}

template <typename ...T>
void wrapper(T&&... para) {
    (process(std::forward<T>(para)), ...);
}

int main() {
    int a = 10;
    int b = 20;
    wrapper(a, b);
    wrapper(std::move(a), b);
    wrapper(20, 30);
}