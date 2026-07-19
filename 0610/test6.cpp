// 要求：定义一个class和一个struct，它们各自包含一个整型成员变量和一个成员函数用于设置该变量的值。
// 在main函数中创建这两个类型的对象，并尝试从类外部直接访问它们的成员变量。观察编译器的行为并解释原因。
// 验收标准：
// class的成员变量在类外部无法直接访问，需要通过成员函数来访问。
// struct的成员变量在类外部可以直接访问（如果未设置访问权限为private）。
#include <iostream>
using std::cout;

class Node {
    int data_;
    void SetData(int a) {
        data_ = a;
    }
};

struct NodeStru {
    int data;
    void SetData(int a) {
        data = a;
    }
};

int main()
{
    Node node;
    NodeStru nodestru;
    // node.SetData(10); // 编译报错
    nodestru.SetData(20);
    // cout << node.data_ << "\n"; // 编译报错
    cout << nodestru.data << "\n";
}