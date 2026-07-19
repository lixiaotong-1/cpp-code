// 题目：实现一个简单的RAII封装类ScopedPtr

// 要求：
// 实现一个ScopedPtr类，用于管理动态分配的内存。该类应该具备以下特性：
// 1.构造函数接受一个指向动态分配内存的指针，并管理该内存。
// 2.析构函数负责释放该内存。
// 3.禁用拷贝构造函数和拷贝赋值运算符，以避免复制导致的双重释放问题。
// 4.提供一个成员函数来访问指向的内存（通过返回裸指针或引用，但需要注意安全性和用途）。
// 5.提供一个移动构造函数和移动赋值运算符（如果需要的话，视具体实现而定）。

// 验收标准：
// 1.ScopedPtr类应能正确管理动态分配的内存，确保在对象生命周期结束时自动释放内存。
// 2.尝试拷贝ScopedPtr对象时应编译失败（或运行时失败，如果未禁用拷贝构造函数但以其他方式防止拷贝）。
// 3.ScopedPtr应提供一个安全的方式来访问其管理的内存（如通过成员函数返回一个裸指针或引用），但不应允许通过该访问方式改变ScopedPtr内部的状态或导致资源被提前释放。
// 4.如果实现了移动构造函数和移动赋值运算符，则它们应能正确地将资源从一个ScopedPtr对象转移到另一个对象，并确保原对象在转移后处于安全状态（通常是设置为空指针）。

// 编程提示：
// 可以使用std::unique_ptr作为参考或实现的基础，但请尝试自己从头开始实现一个简化版的ScopedPtr，以加深理解。注意，这里要求禁用拷贝操作，你需要将拷贝构造函数和拷贝赋值运算符声明为delete。
#include <iostream>
template<class T>
class ScopedPtr {
public:
    ScopedPtr(const ScopedPtr&) = delete;
    ScopedPtr& operator=(const ScopedPtr&) = delete;
    ScopedPtr(ScopedPtr&& scope) noexcept {
        scopeptr = scope.scopeptr;
        scope.scopeptr = nullptr;
    }
    ScopedPtr& operator=(ScopedPtr&& scope) noexcept {
        if (&scope == this) {
            return *this;
        }
        delete scopeptr;
        scopeptr = scope.scopeptr;
        scope.scopeptr = nullptr;
        return *this;
    } 
    explicit ScopedPtr(T* ptr): scopeptr(ptr) {
        std::cout << "调用了构造函数" << "\n";
    }
    ~ScopedPtr() {
        std::cout << "调用了析构函数" << "\n";
        delete scopeptr;
    }
    const T* getScopePtr() const {
        return scopeptr;
    }
private:
    T* scopeptr;
};

int main() {
    int* ptr = new int(4);
    ScopedPtr<int> scope(ptr);
    std::cout << scope.getScopePtr() << "\n";
    // scope.getScopePtr() = &ptr; // 不可修改
    // ScopedPtr<int> newptr(scope); // 编译报错了
    ScopedPtr<int> newptr(std::move(scope));
    std::cout << newptr.getScopePtr() << "\n";
    std::cout << scope.getScopePtr() << "\n";
}