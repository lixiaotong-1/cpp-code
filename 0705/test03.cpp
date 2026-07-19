// 题目1：C++风格的强制类型转换
// 要求：编写一个C++程序，定义两个类Base和Derived，其中Derived继承自Base。
// 在主函数中，创建Derived对象并通过基类指针访问它，然后使用dynamic_cast将基类指针安全地转换为派生类指针，并调用派生类的成员函数。如果转换失败，请输出错误信息。
// 验收标准：
// 1.程序定义了Base和Derived类，且Derived类继承自Base类。
// 2.在主函数中，成功创建了Derived对象，并通过基类指针访问它。
// 3.正确使用了dynamic_cast将基类指针转换为派生类指针，并调用了派生类的成员函数。
// 4.如果转换失败（虽然在这个场景下不太可能），则输出了错误信息。
// #include <iostream>
// class Base {
// public:
//     virtual ~Base() {}
//     virtual void print() const {
//         std::cout << "base" << "\n";
//     }
// };

// class Derived: public Base {
// public:
//     void print() const override {
//         std::cout << "derived" << "\n";
//     }
//     void printInfo() const {
//         std::cout << "derived function" << "\n";
//     }
// };

// int main() {
//     Base* ptr = new Derived();
//     ptr->print();
//     Derived* newptr = dynamic_cast<Derived*>(ptr);
//     if (newptr != nullptr) {
//         newptr->print();
//         newptr->printInfo();
//     }
// }

// 题目2：const_cast的使用
// 要求：编写一个C++程序，定义一个带有const修饰的成员函数的类，该函数返回一个指向类内部成员的const指针。
// 然后，在主函数中，通过const_cast去除const属性，并修改该成员的值。
// 验收标准：
// 1.类定义正确，包含一个const成员函数，该函数返回一个指向类内部成员的const指针。
// 2.在主函数中，成功调用了该成员函数，并通过const_cast去除了const属性。
// 3.修改了原本应为const的成员的值，并验证了修改结果。
// 注意：虽然题目要求这样做，但在实际编程中，滥用const_cast来修改本应为const的数据是不推荐的，因为它破坏了类型安全。此题目仅用于理解const_cast的用法和限制。
// #include <iostream>

// class Base {
// public:
//     Base(int n): num(n) {}
//     const int* getPtr() const {
//         return &num;
//     }
//     void printNum() const {
//         std::cout << "num = " << num << "\n";
//     }
// private:
//     int num;
// };

// int main() {
//     Base base(10);
//     base.printNum();
//     int* ptr = const_cast<int*>(base.getPtr());
//     *ptr = 20;
//     base.printNum();
// }


// 题目3：static_cast 的基本使用
// 要求：编写一个C++程序，定义一个基类Base和一个派生类Derived，其中Derived类有一个额外的成员变量。
// 在主函数中，创建一个Derived对象，并使用static_cast将Derived*转换为Base*，然后通过这个基类指针访问派生类共有的成员变量（如果有的话）。
// 接着，尝试（但不应成功）使用static_cast将Base*转换回Derived*（因为这里缺少类型信息，应该使用dynamic_cast或确保转换是安全的）。
// 验收标准：
// 1.程序定义了Base和Derived类，且Derived类继承自Base类。
// 2.在主函数中，成功创建了Derived对象，并使用static_cast将其指针转换为Base*。
// 3.通过基类指针成功访问了派生类的共有成员变量（如果有）。
// 4.尝试将Base*转换回Derived*时，明确指出了这种转换通常是不安全的，并解释了为什么应该使用dynamic_cast或确保转换的上下文是安全的。
// 注意：实际上，直接尝试将Base*（未知是否确实指向Derived对象）转换回Derived*会导致未定义行为，除非在运行时能够确认这种转换是安全的。
// 因此，这个题目的重点在于理解static_cast的局限性，并认识到何时应该使用其他类型的转换。
// #include <iostream>
// class Base {
// public:
//     Base(int n = 0): num(n) {}
//     virtual ~Base() {}
//     int getNum() const {
//         std::cout << "base num = " << num << "\n";
//         return num;
//     }
// private:
//     int num;
// };

// class Derived: public Base {
// public:
//     Derived(int num): Base(num), denum(num) {}
//     int getDenum() const {
//         std::cout << "derived num = " << denum << "\n";
//         return denum;
//     }
// private:
//     int denum;
// };

// int main() {
//     Derived d(10);
//     Base* bptr = static_cast<Base*>(&d);
//     bptr->getNum();
//     Derived* dptr = static_cast<Derived*>(bptr); // 可能会导致未定义的对象，应该使用dynamic_cast
//     dptr->getDenum();
// }


// 题目4：reinterpret_cast 的使用与风险
// 要求：编写一个C++程序，定义一个整型数组和一个字符指针。
// 使用reinterpret_cast将整型数组的指针转换为字符指针，并尝试通过字符指针访问数组的前几个字节（以展示内存内容的不同解释方式）。
// 验收标准：
// 1.程序定义了整型数组和字符指针。
// 2.成功使用了reinterpret_cast将整型数组的指针转换为字符指针。
#include <iostream>
#include <iomanip>

int main() {
    int arr[3] = {13, 24, 30};
    char* cptr = reinterpret_cast<char*>(&arr[0]);
    std::cout << std::hex << std::setfill('0');
    for (int i = 0; i < sizeof(arr); ++i) {
        int byte = static_cast<unsigned char>(cptr[i]);
        std::cout << std::setw(2) << byte << " ";
    }
    std::cout << "\n";
}