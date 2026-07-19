// 要求：编写一个可变参数模板函数sum，该函数能够接收任意数量的整数参数，并返回它们的和。

// 验收标准：
// 1.函数模板sum被正确定义，能够接收任意数量的整数参数。
// 2.函数能够正确计算并返回所有参数的和。
// 3.在main函数中，成功调用了sum函数的不同实例，并输出了正确的结果。
#include <iostream>
template <typename... T>
int sum1(T... nums) {
    return (... + nums);
}

template <typename T1, typename... T2>
int sum2(T1 num1, T2... resnum) {
    return (num1 + ... + resnum);
}

int sum3() {
    return 0;
}

template <typename T1, typename... Args>
T1 sum3(T1 num, Args... res) {
    return num + sum3(res...);
}

int main() {
    std::cout << sum1(1, 2, 3, 4) << "\n";
    std::cout << sum2(3, 4 ,5 ,6) << "\n";
    std::cout << sum3(3, 4 ,5 ,6) << "\n";
}