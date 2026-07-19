// 题目1：函数重载示例
// 要求：编写一个C++程序，包含三个重载版本的print函数，分别接受int、double和const char*类型的参数，并分别输出其值。
// 在主函数中调用这三个重载版本的print函数。
// 验收标准：
// 程序定义了三个print函数，分别接受不同类型的参数。
// 主函数中成功调用了这三个重载版本的print函数，并输出了预期的结果。
#include <iostream>

void Print(int a)
{
    std::cout << "int num is " << a << "\n";
}

void Print(double a)
{
    std::cout <<  "double num is " << a << "\n";
}

void Print(const char* str)
{
    std::cout << "string value is " << str << "\n";
}

int main()
{
    int a = 10;
    double b = 4.0;
    const char* str = "hello world.";
    Print(a);
    Print(b);
    Print(str);
}

