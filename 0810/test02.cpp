// 题目1：tuple的基本操作
// 要求：编写一个C++程序，定义一个std::tuple<int, std::string, double>对象，并初始化它。
// 然后，分别使用std::get和结构化绑定（如果编译器支持C++17及以上）访问并打印出tuple中的每个元素。
// 验收标准：
// 1. 程序能够正确定义并初始化std::tuple<int, std::string, double>对象。
// 2. 程序能够使用std::get正确访问并打印出tuple中的每个元素。
// 3. 如果编译器支持C++17及以上，程序能够使用结构化绑定简化元素的访问并打印它们。
// #include <tuple>
// #include <string>
// #include <iostream>

// int main() {
//     auto tp = std::make_tuple(12, "hello", 23.09);
//     std::cout << std::get<0>(tp) << "\n";
//     std::cout << std::get<1>(tp) << "\n";
//     std::cout << std::get<2>(tp) << "\n";

//     auto [num, str, dval] = tp;
//     std::cout << num << "\n";
//     std::cout << str << "\n";
//     std::cout << dval << "\n";
// }

// 题目2：tuple与函数返回多个值
// 要求：编写一个C++函数，该函数计算并返回一个整数数组的最大值、最小值和平均值（作为一个std::tuple<int, int, double>返回）。
// 然后，在主函数中调用该函数，并使用结构化绑定（如果可用）接收返回值，打印出这些值。
// 验收标准：
// 1. 函数能够正确地计算并返回一个整数数组的最大值、最小值和平均值，封装在std::tuple<int, int, double>中。
// 2. 主函数能够调用该函数，并使用结构化绑定（如果编译器支持）或std::get正确地接收并打印出这些值。
#include <tuple>
#include <vector>
#include <string>
#include <iostream>

std::tuple<int, int ,double> getMaxMinAvg(const std::vector<int>& vec) {
    if (vec.size() == 0) {
        return std::make_tuple(0, 0, 0);
    }
    int max_num = INT_MIN;
    int min_num = INT_MAX;
    int sum = 0;
    for (const auto& num: vec) {
        if (num > max_num) {
            max_num = num;
        }
        if (num < min_num) {
            min_num = num;
        }
        sum += num;
    }
    int avg = 1.0 * sum / vec.size();
    auto res = std::make_tuple(max_num, min_num, avg);
    return res;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    auto res = getMaxMinAvg(vec);
    auto [num1, num2, num3] = res;
    std::cout << num1 << ", " << num2 << ", " << num3 << "\n";
}
