// 题目1：编写一个C++程序，展示nullptr与NULL（或0）在类型安全方面的区别。
// 程序应包含至少两个函数，一个接收int*类型参数，另一个接收int类型参数。
// 在调用这两个函数时，分别使用nullptr、NULL和0作为参数，并观察编译器的警告或错误（如果有的话）。
// 验收标准：
// 程序应能成功编译（尽管可能包含一些编译器警告，这取决于编译器的具体实现和警告级别）。
// 应通过注释或打印语句说明在哪些情况下nullptr提供了更好的类型安全性，而NULL或0可能导致类型不明确或警告。
// #include <iostream>

// void fun(int* a)
// {
//     std::cout << "fun(int* a)" << "\n";
// }

// void fun(int a)
// {
//     std::cout << "fun(int a)" << "\n";
// }

// int main()
// {
//     fun(nullptr);
//     fun(0);
//     // fun(NULL);
// }



// 题目2：编写一个C++程序，定义一个整型指针int* ptr，并使用nullptr初始化它。
// 然后，编写一个条件判断语句来检查ptr是否为空，如果是，则打印一条消息表示指针未指向任何有效内存。
// 验收标准：
// 程序应能正确初始化指针ptr为nullptr。
// 条件判断语句应能准确检测到ptr为空，并打印相应的消息。
// #include <iostream>

// int main()
// {
//     int* ptr = nullptr;
//     if (ptr == nullptr) {
//         std::cout << "指向无效内存" << "\n";
//     } else {
//         std::cout << "指向有效内存" << "\n";
//     }
// }


// 题目3：编写一个C++函数，该函数接收一个整型指针int* ptr作为参数，并检查该指针是否为nullptr。
// 如果不是nullptr，则函数应打印出指针所指向的整数值；如果是nullptr，则打印一条消息表示未接收到有效的指针。
// 然后，在主函数中调用这个函数，并分别传递一个有效的整型指针和一个nullptr作为参数。
// 验收标准：
// 函数应能正确检查传入的指针是否为nullptr。
// 当传入有效的整型指针时，函数应能正确打印出指针所指向的整数值。
// 当传入nullptr时，函数应能打印出相应的消息，表示未接收到有效的指针。
#include <iostream>

void func(int* ptr)
{
    if (ptr == nullptr) {
        std::cout << "指向无效地址" << "\n";
    } else {
        std::cout << "*ptr = " << *ptr << "\n";
    }
}

int main()
{
    int a = 10;
    func(&a);
    func(nullptr);
}
