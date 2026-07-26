// 题目1：迭代器的基本操作
// 要求：编写一个C++程序，定义一个std::vector<int>容器，包含5个元素{1, 2, 3, 4, 5}。使用迭代器遍历并打印容器中的所有元素。
// 验收标准：
// 程序能够正确创建并初始化std::vector<int>容器。
// 程序能够使用迭代器遍历并打印出容器中的所有元素。
// #include <iostream>
// #include <vector>
// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     auto iter = vec.begin();
//     while (iter != vec.end()) {
//         std::cout << *iter << " ";
//         ++iter;
//     }
//     std::cout << "\n";
// }

// 题目2：迭代器与算法的结合
// 要求：编写一个C++函数，该函数接收两个std::vector<int>的迭代器（分别表示起始和结束位置）作为参数，并使用std::sort算法对指定范围内的元素进行排序。
// 然后，在主函数中测试该函数。
// 验收标准：
// 函数能够正确接收迭代器参数。
// 函数内部能够正确调用std::sort算法对指定范围内的元素进行排序。
// 主函数中能够正确调用该函数，并验证排序结果。
// #include <iostream>
// #include <vector>
// #include <algorithm>

// void sortFun(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
//     std::sort(begin, end);
// }

// int main() {
//     std::vector<int> vec = {3, 6, 8, 1, 0, 8, 4, 90, -3};
//     sortFun(vec.begin(), vec.end());
//     for (std::vector<int>::iterator iter = vec.begin(); iter < vec.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << "\n";
// }


// 题目3：迭代器失效的示例
// 要求：编写一个C++程序，定义一个std::vector<int>容器，并演示在插入元素时迭代器失效的情况。
// 具体来说，你可以使用一个迭代器指向容器的某个元素，然后在迭代器指向的元素之前插入一个新元素，并尝试通过该迭代器访问原始元素（这将导致未定义行为）。
// 为了安全起见，你可以在尝试访问之前先打印出迭代器的值，然后插入新元素，并指出迭代器已失效。
// 注意：由于直接访问失效的迭代器会导致未定义行为，因此这里只是要求演示迭代器失效的情况，而不是真的去访问它。
// 验收标准：
// 程序能够正确创建并初始化std::vector<int>容器。
// 程序能够演示在插入元素时迭代器失效的情况。
// 程序能够指出在插入新元素后，原始迭代器已失效，并避免尝试通过它访问元素。
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {3, 4, 1, 2, 5};
    std::vector<int>::iterator iter = vec.begin() + 1;
    std::cout << *iter << "\n";
    vec.insert(iter, 10);
    // 插入之后，容器可能扩容导致迭代器失效，即使不扩容，插入点以及以后的迭代器都失效
    for (int num: vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}