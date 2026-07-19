// 题目2：解决重载歧义
// 要求：编写一个C++程序，其中包含两个重载函数show，一个接受int类型的参数，另一个接受float类型的参数。
// 然后，尝试编写一个函数调用show，其参数在编译时可能既可以是int类型也可以是float类型（例如，使用字面量3.0，但没有明确的小数点或类型后缀），
// 并解释如何修改这个调用以避免编译器的重载歧义错误。
// 验收标准：
// 程序包含两个重载的show函数，分别接受int和float类型的参数。
// 尝试了一个可能导致重载歧义的函数调用，并解释了为什么会出现这个问题。
// 提供了修改函数调用以避免歧义的方法，并展示了修改后的代码和输出结果。
#include <iostream>

void show(int num)
{
    std::cout << "int num is " << num << "\n";
}

void show(float num)
{
    std::cout << "float num is " << num << "\n";
}

int main()
{
    int a = 90;
    float b = 4;
    show(a);
    show(b);
    show(3.0f);
    show(static_cast<int>(3.0));

}