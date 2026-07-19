// 题目1：单个对象的动态内存分配与释放
// 编写一个C++程序，定义一个简单的类（例如，Point类，包含x和y两个整型成员变量），使用new操作符动态分配一个Point对象，
// 并通过指针访问其成员变量，最后使用delete操作符释放该对象。
// 验收标准：
// 1.程序应能正确创建并初始化一个Point对象。
// 2.应能通过指针正确访问并修改Point对象的成员变量。
// 3.应能正确释放分配给Point对象的内存，避免内存泄漏。
// #include <iostream>

// class Point {
// public:
//     Point(int x = 0, int y = 0): x(x), y(y) {}
//     ~Point() {}
//     int x;
//     int y;
// };

// int main() {
//     Point* p = new Point(2, 4);
//     std::cout << p->x << "," << p->y << "\n";
//     p->x = 20;
//     p->y = 40;
//     std::cout << p->x << "," << p->y << "\n";
//     delete p;
//     p = nullptr;
// }

// 题目2：对象数组的动态内存分配与释放
// 扩展题目1中的Point类，编写一个C++程序，使用new[]操作符动态分配一个包含5个Point对象的数组，
// 并通过指针数组遍历并打印每个Point对象的x和y值，最后使用delete[]操作符释放该数组。
// 验收标准：
// 1.程序应能正确创建并初始化一个包含5个Point对象的数组。
// 2.应能通过指针数组正确访问并打印每个Point对象的成员变量。
// 3.应能正确释放分配给Point对象数组的内存，避免内存泄漏。
// #include <iostream>

// class Point {
// public:
//     Point(int x = 0, int y = 0): x(x), y(y) {
//         std::cout << "调用了一次构造函数" << "\n";
//     }
//     ~Point() {
//         std::cout << "调用了一次析构函数" << "\n";
//     }
//     int x;
//     int y;
// };

// int main() {
//     Point* p = new Point[5];
//     for (int i = 0; i < 5; ++i) {
//         p[i].x = i;
//         p[i].y = i;
//         std::cout << "p.x = " << p->x << " p.y = " << p->y << "\n";
//     }
//     delete[] p;
//     p = nullptr;
// }

// 题目3：异常处理
// 修改题目2中的程序，增加异常处理机制，以便在new[]分配内存失败时捕获std::bad_alloc异常，并打印一条错误消息。
// 验收标准：
// 1.程序应能捕获std::bad_alloc异常。
// 2.当内存分配失败时，应能打印出相应的错误消息。
// 3.其余部分应符合题目2的验收标准。
#include <iostream>

class Point {
public:
    Point(int x = 0, int y = 0): x(x), y(y) {
        std::cout << "调用了一次构造函数" << "\n";
    }
    ~Point() {
        std::cout << "调用了一次析构函数" << "\n";
    }
    int x;
    int y;
};

int main() {
    try {
        Point* p = new Point[5];
        for (int i = 0; i < 5; ++i) {
            p[i].x = i;
            p[i].y = i;
            std::cout << "p.x = " << p->x << " p.y = " << p->y << "\n";
        }
        delete[] p;
        p = nullptr;
    } catch (const std::bad_alloc& e){
        std::cout << "bad allocated" << "\n";
        std::cout << e.what() << "\n";
        return 1;
    }
}