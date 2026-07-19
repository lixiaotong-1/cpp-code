// 要求：定义一个基类Base（使用class或struct均可），它包含一个public的整型成员变量。
// 然后定义一个派生类Derived，它继承自Base，但不修改继承方式（默认继承）。在main函数中创建Derived类的对象，并尝试访问基类中的成员变量。
// 验收标准：
// 如果基类使用class定义，则派生类无法直接访问基类的成员变量（除非显式声明为public继承）。
// 如果基类使用struct定义，则派生类可以直接访问基类的成员变量。
#include <iostream>
using std::cout;

struct Base {
    int data_;
};

struct Derived: Base {

};

class Base1 {
public:
    int data_;
};

class Derived1: Base1 {

};

int main()
{
    Derived d;
    Derived1 d1;
    cout << d.data_ << "\n"; // struct默认是公有继承
    // cout << d1.data_ << "\n"; // 编译报错,class默认是私有继承
}