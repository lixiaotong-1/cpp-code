// 题目1：函数模板的使用
// 要求：编写一个函数模板max，该函数接受两个参数并返回它们中的较大值。在main函数中，测试该函数模板对于整型、浮点型和字符型数据的处理能力。
// 验收标准：
// 1.函数模板max被正确定义，能够处理不同类型的参数。
// 2.在main函数中，成功调用了max函数模板的多个实例，分别传递了整型、浮点型和字符型参数，并输出了正确的结果。
// #include <iostream>

// template <typename T>
// T max(const T& a, const T& b) {
//     return a > b ? a : b;
// }

// int main() {
//     int ret1 = max(2, 3);
//     std::cout << ret1 << "\n";

//     double ret2 = max(3.0, 7.5);
//     std::cout << ret2 << "\n";

//     char ret3 = max('d', 'p');
//     std::cout << ret3 << "\n";
// }

// 题目2：类模板的使用
// 要求：定义一个类模板Box，用于表示一个具有长度、宽度和高度的盒子。
// 该类模板应包含构造函数、设置器（setter）和获取器（getter）方法，以及一个计算体积的成员函数。在main函数中，实例化Box模板的多个实例，
// 分别代表不同类型的盒子（如整型、浮点型等），并计算它们的体积。
// 注意：为了简化问题，本题不要求实际处理不同类型的长度、宽度和高度（如整型、浮点型混用），而是要求展示类模板的基本用法和实例化。
// 验收标准：
// 1.类模板Box被正确定义，包含所需的成员函数。
// 2.在main函数中，成功实例化了Box模板的多个实例，分别传递了不同类型的参数（尽管在本题中这些类型主要用于展示，并不实际影响计算结果）。
// 3.成功调用了这些实例的获取器和计算体积的成员函数，并输出了正确的结果。
#include <iostream>

template < typename T>
class Box {
public:
    Box(const T& len = 0, const T& wid = 0, const T& hi = 0): length(len), width(wid), height(hi) {}
    T calV() const {
        return length * width * height;
    }
    void setterL(const T& len) {
        length = len;
    }
    void setterW(const T& wid) {
        width = wid;
    }

    void setterH(const T& hi) {
        height = hi;
    }

    T getterL() const {
        return length;
    }

    T getterW() const {
        return width;
    }

    T getterH() const {
        return height;
    }

private:
    T length;
    T width;
    T height;
};

int main() {
    Box<int> b(2, 3, 4);
    std::cout << "长：" << b.getterL() << ", 宽：" << b.getterW() << ", 高：" << b.getterH() << "\n";
    std::cout << "v = " << b.calV() << "\n";
    Box<double> c;
    c.setterL(9.8);
    c.setterW(3.2);
    c.setterH(4.0);
    std::cout << "长：" << c.getterL() << ", 宽：" << c.getterW() << ", 高：" << c.getterH() << "\n";
    std::cout << "v = " << c.calV() << "\n";
}