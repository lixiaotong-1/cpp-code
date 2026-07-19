// 题目1：静态局部变量与全局变量的区别
// 要求：编写一个C++程序，展示静态局部变量和全局变量的区别。程序应包括一个函数，该函数内部有一个静态局部变量和一个全局变量，函数被多次调用时，观察并记录这两个变量的行为。
// 验收标准：
// 1.程序包含了一个全局变量和一个在函数内部定义的静态局部变量。
// 2.函数被多次调用，每次调用时都打印这两个变量的值，并修改它们。
// #include<iostream>

// int gloabalVar = 10;

// void testFun() {
//     static int localStaticVar = 20;
//     ++localStaticVar;
//     ++gloabalVar;
//     std::cout << "local static var = " << localStaticVar << "\n";
//     std::cout << "global var = " << gloabalVar << "\n";
// }

// int main() {
//     for (int i = 0; i < 5; ++i) {
//         testFun();
//     }
// }

// 题目2：静态成员变量的使用
// 要求：定义一个类Counter，该类有一个静态成员变量用于记录创建的对象数量。类中包含一个构造函数，该构造函数在每次创建对象时递增静态成员变量的值。
// 同时，类中包含一个静态成员函数用于返回当前对象的总数。
// 验收标准：
// 1.Counter类定义正确，包含一个静态成员变量和一个静态成员函数。
// 2.静态成员变量在类外部被正确定义和初始化（如果需要在程序开始时就有初始值）。
// 3.构造函数在每次创建Counter对象时都正确地递增静态成员变量的值。
// 4.静态成员函数能够正确返回当前对象的总数。
// #include<iostream>
// class Counter {
//     public:
//         Counter() {
//             ++a;
//         }
//         static int getObjNum() {
//             return a;
//         }
//     private:
//         static int a;
// };

// int Counter::a = 0;

// int main() {
//     Counter c1;
//     Counter c2;
//     std::cout << "obj num = " << Counter::getObjNum() << "\n";
//     Counter c3;
//     Counter c4;
//     std::cout << "obj num = " << Counter::getObjNum() << "\n";
// }

// 题目3：静态成员函数的限制
// 要求：编写一个C++程序，定义一个类BankAccount，该类包含静态和非静态成员函数。静态成员函数尝试访问类的非静态成员变量，并捕获编译时错误。
// 然后，通过修改代码来展示如何在静态成员函数中通过对象实例来访问非静态成员。
// 验收标准：
// 1.BankAccount类定义正确，包含至少一个静态成员函数和一个非静态成员变量。
// 2.静态成员函数最初尝试直接访问非静态成员变量，导致编译时错误。
// 3.展示了如何通过修改代码（例如，将非静态成员变量的访问移至非静态成员函数或通过对象实例传递）来修复编译错误。
#include <iostream>

class BankAccount {
public:
    // static void printNum() {
    //     std::cout << "num = " << num << "\n";
    // }
    /* 不能通过static函数访问非static成员变量，因为静态成员函数没有this指针 */
    BankAccount(int n): num(n) {}
    void printNum() {
        std::cout << "num = " << num << "\n";
    }
private:
    int num;
};

int main() {
    BankAccount ba(10);
    ba.printNum();
}