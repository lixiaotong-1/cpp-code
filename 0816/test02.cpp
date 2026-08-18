// 题目1：shared_ptr 和 weak_ptr 的使用
// 定义两个类 NodeA 和 NodeB，它们相互持有对方的指针。
// 使用 shared_ptr 和 weak_ptr 管理 NodeA 和 NodeB 的生命周期。
// 展示如何通过 weak_ptr 避免循环引用，并确保资源被正确释放。
// 在程序中检查 weak_ptr 是否已过期。
// #include <iostream>
// #include <memory>
// class NodeA;
// class NodeB;

// class NodeA {
// public:
//     std::shared_ptr<NodeB> _ptr;
//     NodeA() {
//         std::cout << "construction NodeA" << "\n";
//     }
//     ~NodeA() {
//         std::cout << "deconstruction NodeA" << "\n";
//     }
// };

// class NodeB {
// public:
//     std::weak_ptr<NodeA> _ptr;
//     NodeB() {
//         std::cout << "construction NodeB" << "\n";
//     }
//     ~NodeB() {
//         std::cout << "deconstruction NodeB" << "\n";
//     } 
//     void show() const {
//         if (_ptr.expired()) {
//             std::cout << "NodeA 对象已经销毁，weak_ptr已经过期" << "\n";
//             return;
//         }
//         std::shared_ptr<NodeA> tmp = _ptr.lock();
//         if (tmp) {
//             std::cout << "NodeA 获取成功，可以正常使用" << "\n";
//         }

//     }
// };

// int main() {
//     std::shared_ptr<NodeA> sp1 = std::make_shared<NodeA>();
//     std::shared_ptr<NodeB> sp2 = std::make_shared<NodeB>();
//     sp1->_ptr = sp2;
//     sp2->_ptr = sp1;
//     sp2->show();
//     std::cout << "打印引用计数" << "\n";
//     std::cout << "NodeB refcout = " << sp2.use_count() << "\n";
//     std::cout << "NodeA refcout = " << sp1.use_count() << "\n";
// }

// 题目2：unique_ptr 的使用
// 要求：编写一个 C++ 函数，该函数接收一个整数 n，动态分配一个整型数组并初始化为 1 到 n 的值，然后使用 unique_ptr 管理该数组。
// 函数应返回一个指向数组第一个元素的指针（注意：这里返回裸指针是为了演示目的，实际应用中应尽量避免）。
// 另外，编写一个 main 函数测试该函数，验证数组是否按预期初始化，并在函数返回后检查数组是否仍然有效（通过打印数组内容）。
// 注意：虽然这里返回了裸指针，但验收时应关注 unique_ptr 的正确使用以及它如何确保数组在适当的时候被销毁。
// 验收标准：
// 1. 函数能够正确创建并初始化整型数组。
// 2. unique_ptr 正确管理了数组的生命周期，确保在函数返回后数组仍然有效（尽管通过裸指针访问）。
// 3. main 函数能够验证数组是否按预期初始化。
// #include <iostream>
// #include <memory>

// int* alloc_array(int n, std::unique_ptr<int[]>& out_up) {
//     int* p = new int[n]();
//     out_up = std::unique_ptr<int[]>(p);
//     for (int i = 0; i < n; ++i) {
//         out_up[i] = i + 1;
//     }
//     return out_up.get();
// }

// int main() {
//     std::unique_ptr<int[]> holder1;
//     int* p1 = alloc_array(10, holder1);

//     std::unique_ptr<int[]> holder2;
//     int* p2 = alloc_array(5, holder2);

//     for (int i = 0; i < 10; ++i) {
//         std::cout << p1[i] << " ";
//     }
//     std::cout << "\n";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << p2[i] << " ";
//     }
//     std::cout << "\n";
// }

// 题目3：智能指针的异常安全
// 要求：编写一个 C++ 程序，其中包含一个可能抛出异常的函数，该函数使用 shared_ptr 管理资源。
// 在 main 函数中调用此函数，并处理可能抛出的异常。验证即使在异常发生时，由 shared_ptr 管理的资源也能被正确释放。
// 验收标准：
// 1. 程序能够正确处理可能由被调用函数抛出的异常。
// 2. 在异常发生时，由 shared_ptr 管理的资源能够被正确释放，没有内存泄漏。
#include <iostream>
#include <memory>
#include <exception>

void func(int m, int n) {
    std::shared_ptr<int> sp1 = std::make_shared<int>(n);
    std::cout << "use count = " << sp1.use_count() << "\n";
    if (*sp1 == 0) {
        throw std::runtime_error("divided by zero");
    }
    int res = m / *sp1;
    std::cout << "res = " << res << "\n";
}

int main() {
    int m = 10, n = 0;
    try {
        func(m, n);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << "main end" << "\n";
}