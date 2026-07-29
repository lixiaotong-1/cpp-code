// 题目1：C风格数组的遍历与打印
// 要求：编写一个C++程序，定义一个整型C风格数组arr，包含5个元素{1, 2, 3, 4, 5}，通过指针遍历并打印数组中的所有元素。
// 验收标准：
// 1. 程序能够正确定义并初始化C风格数组。
// 2. 程序能够使用指针遍历数组，并打印出所有元素。
// 3. 遍历过程中不出现越界访问。
// #include <iostream>

// int main() {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int* p = &arr[0];
//     int* end = p + sizeof(arr) / sizeof(arr[0]);
//     while (p != end) {
//         std::cout << *p << " ";
//         ++p;
//     }
//     std::cout << "\n";
// }

// 题目2：std::array的使用与遍历
// 要求：编写一个C++程序，定义一个std::array<int, 5>对象arr，并使用列表初始化方式初始化为{1, 2, 3, 4, 5}。然后，使用范围for循环遍历并打印arr中的所有元素。
// 验收标准：
// 1. 程序能够正确定义并初始化std::array对象。
// 2. 程序能够使用范围for循环遍历std::array，并打印出所有元素。
// 3. 遍历过程中不出现任何错误。
// #include <iostream>
// #include <array>

// int main() {
//     std::array<int, 5> arr = {1, 2, 3, 4, 5};
//     for (const auto& n: arr) {
//         std::cout << n << " ";
//     }
//     std::cout << "\n";
// }

// 题目3：std::array的元素修改与验证
// 要求：编写一个C++函数，该函数接收一个std::array<int, 5>的引用作为参数，通过成员函数或operator[]修改数组中的每个元素，使其值加倍。
// 然后，在主函数中定义并初始化一个std::array<int, 5>对象，调用该函数，并使用范围for循环验证修改后的数组元素。
// 验收标准：
// 1. 函数能够正确接收std::array的引用作为参数。
// 2. 函数能够修改数组中的每个元素，使其值加倍。
// 3. 主函数能够正确调用该函数，并使用范围for循环验证修改结果。
// 4. 验证过程中不出现任何错误，且所有元素的值均正确加倍。
#include <iostream>
#include <array>

void func(std::array<int, 5>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] *= 2;
    }
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    func(arr);
    for (const auto& n: arr) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}