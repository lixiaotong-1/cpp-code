// 题目1：const变量的基本使用
// 1.声明一个const整型变量并初始化。
// 2.尝试修改该变量的值，并确保编译器报错。
#include <iostream>

// int main() {
//     const int a = 10;
//     a = 12;
// }

// 题目2：const指针的使用
// 1.声明一个指向const整数的指针，并通过该指针初始化一个整数。
// 2.尝试通过指针修改其指向的值，确保编译器报错。
// 3.声明一个指针常量，并初始化它指向一个整数。
// 4.尝试修改指针常量的值（即让它指向另一个地址），确保编译器报错。
// int main() {
//     int a = 10;
//     const int* p = &a;
//     // *p = 20;
//     int b = 8;
//     int * const q = &b;
//     q = &a;
// }


// 题目3：const修饰函数参数和返回值
// 1.编写一个函数，其参数为const引用，用于输出参数的值但不修改它。
// 2.编写一个函数，其返回值为const指针，指向一个静态或全局变量，确保返回的指针指向的内容不能被修改。

// void modPara(const int& a) {
//     std::cout << a << std::endl;
// }

// static int a = 10;
// const int* getstaticVar() {
//     return &a;
// }

// int main() {
//     int a = 10;
//     modPara(a);
//     const int* p = getstaticVar();
//     std::cout << "*p=" << *p << "\n";
//     // *p = 20;
// }

// 题目4：const成员函数
// 1.编写一个类，其中包含至少一个成员变量和一个const成员函数。const成员函数应2.保证不修改类的任何成员变量（除了mutable修饰的变量）。
// 3.在main函数中创建该类的对象，并调用const成员函数，验证其不会修改对象的状态。
class A {
private:
    int num;
    mutable int mutableNum;
public:
    A(): num(0), mutableNum(0) {}
    A(int a, int b): num(a), mutableNum(b) {}
    int getNum() const {
        mutableNum++;
        return num;
    }
    int getMutableNum() const {
        return mutableNum;
    }
};

int main() {
    A a(10, 20);
    int received = a.getNum();
    std::cout << "received num = " << received << "\n";
    int muteNum = a.getMutableNum();
    std::cout << "mutable num = " << muteNum << "\n";

    A b;
    received = b.getNum();
    std::cout << "received num = " << received << "\n";
    muteNum = b.getMutableNum();
    std::cout << "mutable num = " << muteNum << "\n";
}