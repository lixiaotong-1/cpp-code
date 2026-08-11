// 题目1：function 的使用
// 要求：编写一个 C++ 程序，定义一个 std::function<int(int, int)> 类型的变量，
// 分别赋值给一个普通的加法函数、一个 Lambda 表达式和一个使用 std::bind 绑定的加法函数。
// 然后，通过这个 std::function 类型的变量调用这些可调用对象，并打印结果。
// 验收标准：
// 1. 程序能够正确定义 std::function<int(int, int)> 类型的变量。
// 2. 程序能够成功地将加法函数、Lambda 表达式和通过 std::bind 绑定的加法函数赋值给该变量。
// 3. 程序能够通过这个变量正确地调用这些可调用对象，并打印出预期的结果。
// #include <iostream>
// #include <functional>

// int add(int a, int b) {
//     return a + b;
// }

// int main() {
//     std::function<int(int, int)> func = add;
//     int res = func(2, 3);
//     std::cout << res << "\n";
//     func = [] (int a, int b) { return a + b; };
//     res = func(2, 3);
//     std::cout << res << "\n";
//     func = std::bind(add, std::placeholders::_2, std::placeholders::_1);
//     res = func(3, 2);
//     std::cout << res << "\n";
//     return 0;
// }

// 题目2：bind 的使用
// 要求：编写一个 C++ 程序，定义一个普通的减法函数，然后使用 std::bind 绑定这个函数的第一个参数为 10，
// 生成一个新的可调用对象。之后，通过这个新的可调用对象对不同的值进行减法操作，并打印结果。
// 验收标准：
// 1. 程序能够正确定义减法函数并使用 std::bind 绑定其第一个参数。
// 2. 程序能够成功生成新的可调用对象，并对其进行调用。
// 3. 程序能够打印出正确的减法结果。
// #include <iostream>
// #include <functional>

// int sub(int a, int b) {
//     return a - b;
// }

// int main() {
//     std::function<int(int)> func = std::bind(sub, 10, std::placeholders::_1);
    
//     std::cout << func(1) << "\n";
//     std::cout << func(2) << "\n";
//     std::cout << func(3) << "\n";
//     std::cout << func(4) << "\n";
// }

// 题目3：Lambda 表达式的使用
// 要求：编写一个 C++ 程序，定义一个 std::vector<int> 并初始化为 {1, 2, 3, 4, 5}。
// 然后，使用 Lambda 表达式作为参数传递给 std::for_each 算法，对每个元素进行平方操作，
// 并将结果存储回原 vector 中。最后，遍历并打印修改后的 vector。
// 验收标准：
// 1. 程序能够正确定义并初始化 std::vector<int>。
// 2. 程序能够编写正确的 Lambda 表达式，并在其中使用捕获列表捕获外部变量（如果需要）。
// 3. 程序能够成功地将 Lambda 表达式作为参数传递给 std::for_each 算法。
// 4. 程序能够遍历并打印出修改后的 vector，其中的每个元素都是原始元素的平方。
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main() {
    int param = 1;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [&](int& a) {
        a = a * a * param;
    });
    for (const int& num: vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}