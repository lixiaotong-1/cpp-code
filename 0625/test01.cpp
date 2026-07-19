// 题目1：
// 1.编写一个enum class，名为Color，包含RED、GREEN、BLUE三个枚举值。
// 2.编写代码尝试直接访问RED（不通过Color::前缀），并理解为什么编译器会报错。
// 3.编写代码将Color::RED显式转换为int类型，并打印结果。

// 题目2：
// 1.编写一个函数，该函数接收一个Color枚举类型的参数，并根据参数值打印出对应的颜色名称。
// 2.验证函数能够正确处理所有Color枚举值。
#include <iostream>

enum class Color {
    RED,
    GREEN,
    BLUE
};

void printColor(Color c) {
    switch (c)
    {
    case Color::RED:
        std::cout << "red" << "\n";
        break;
    case Color::GREEN:
        std::cout << "green" << "\n";
    case Color::BLUE:
        std::cout << "blue" << "\n";
    default:
        break;
    }
}

int main() {
    // Color c = RED;
    /*
    报错原因：enum class 是强类型枚举，枚举成员作用域被限定在Color内部
    必须写 Color::RED，不能直接裸写 RED
    */
    Color c2 = Color::RED;
    int a = static_cast<int>(c2);
    std::cout << "a = " << a << "\n";
    printColor(c2);
    printColor(Color::GREEN);
    printColor(Color::BLUE);
}