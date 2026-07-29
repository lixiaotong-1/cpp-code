// 题目1：std::vector的基本操作
// 要求：编写一个C++程序，定义一个std::vector<int>，使用push_back方法向其中添加5个整数（如1, 2, 3, 4, 5），然后使用迭代器遍历并打印出所有元素。
// 验收标准：
// 程序能够正确创建并初始化std::vector<int>。
// 程序能够使用push_back方法向vector中添加元素。
// 程序能够使用迭代器正确遍历并打印出vector中的所有元素。
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> vec;
//     for (int i = 0; i < 5; ++i) {
//         vec.push_back(i + 1);
//     }
//     for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << "\n";
// }

// 题目2：std::vector的扩容与访问
// 要求：编写一个C++程序，定义一个std::vector<int>，并动态添加元素直到触发扩容。在每次添加元素后，打印出当前的大小（size()）和容量（capacity()）。
// 最后，通过索引访问并打印出vector中的第一个和最后一个元素。
// 验收标准：
// 程序能够正确跟踪并打印出vector的大小和容量变化。
// 程序能够正确识别扩容事件的发生。
// 程序能够通过索引正确访问并打印出vector中的第一个和最后一个元素。
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    std::cout << "origin size = " << vec.size() << ", capacity = " << vec.capacity() << "\n";
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i + 1);
        std::cout << " 添加第" << i + 1 << "个元素之后，size = " << vec.size() << ", capacity = " << vec.capacity() << "\n";
    }
    std::cout << "第一个元素是" << vec[0] << "\n";
    std::cout << "最后一个元素是" << vec[vec.size() - 1] << "\n";
    vec.reserve(20);
    for (int i = 0; i < vec.capacity(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    vec.resize(25);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

// 题目3：修改std::vector中的元素
// 要求：编写一个C++函数，该函数接收一个std::vector<int>的引用作为参数，并遍历该vector，将所有元素的值加倍。在主函数中测试该函数。
// 验收标准：
// 函数能够正确接收std::vector<int>的引用作为参数。
// 函数内部能够正确遍历vector并修改每个元素的值。
// // 主函数中能够正确调用该函数，并验证vector中所有元素的值是否都已加倍。
// #include <iostream>
// #include <vector>

// void function(std::vector<int>& vec) {
//     for (int& a: vec) {
//         a *= 2;
//     }
// }

// void printVec(const std::vector<int>& vec) {
//     for (const int& a: vec) {
//         std::cout << a << " ";
//     }
//     std::cout << "\n";
// }

// int main() {
//     std::vector<int> vec(10);
//     for (int i = 0; i < vec.size(); ++i) {
//         vec[i] = i + 1;
//     }
//     printVec(vec);
//     function(vec);
//     printVec(vec);
//     return 0;
// }

// 题目4：std::vector的插入与删除操作
// 要求：编写一个C++程序，定义一个std::vector<int>，并初始化为包含5个元素的序列（例如，1, 2, 3, 4, 5）。
// 然后，在第三个元素（值为3的元素）之前插入一个新的元素（值为10），并删除最后一个元素。最后，遍历并打印出修改后的vector中的所有元素。
// 验收标准：
// 程序能够正确初始化std::vector<int>。
// 程序能够使用insert方法在指定位置插入新元素。
// 程序能够使用pop_back方法或迭代器与erase方法删除最后一个元素（具体方法不限）。
// 程序能够正确遍历并打印出修改后的vector中的所有元素。
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     vec.insert(vec.begin() + 2, 10);
//     vec.erase(vec.end() - 1);
//     for (const int& a: vec) {
//         std::cout << a << " ";
//     }
//     std::cout << "\n";
// }

// 题目5：使用std::vector与STL算法
// 要求：编写一个C++程序，首先定义一个std::vector<int>并填充一系列随机整数。
// 然后，使用STL算法（如std::sort进行排序，std::unique去除重复元素，std::find查找特定元素等）对该vector进行处理。
// 最后，遍历并打印出处理后的vector中的所有元素，以及查找特定元素的结果（如果找到）。
// 注意：在使用std::unique后，需要调用erase来真正从vector中移除重复的元素，因为std::unique只是将重复元素移动到容器的末尾，并返回一个指向新逻辑末尾的迭代器。
// 验收标准：
// 程序能够正确初始化并填充std::vector<int>。
// 程序能够使用std::sort对vector进行排序。
// 程序能够使用std::unique（结合erase）去除vector中的重复元素。
// 程序能够使用std::find（或其他查找算法）在vector中查找特定元素，并正确处理查找结果。
// 程序能够正确遍历并打印出处理后的vector中的所有元素，以及查找特定元素的结果（如果找到）。
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>
// #include <ctime>

// void printVec(const std::vector<int>& vec) {
//     for (const int& a: vec) {
//         std::cout << a << " ";
//     }
//     std::cout << "\n";
// }

// int main() {
//     std::vector<int> vec;
//     std::srand(unsigned(std::time(nullptr)));
//     for (int i = 0; i < 10; ++i) {
//         vec.push_back(std::rand() % 10);
//     }
//     std::cout << "随机值初始化数组后" << "\n";
//     printVec(vec);
//     std::sort(vec.begin(), vec.end());
//     std::cout << "堆数组排序后" << "\n";
//     printVec(vec);

//     std::vector<int>::iterator newend = std::unique(vec.begin(), vec.end());
//     vec.erase(newend, vec.end());
//     std::cout << "对数组去重之后" << "\n";
//     // for (auto iter = vec.begin(); iter != newend; ++iter) {
//     //     std::cout << *iter << " ";
//     // }
//     printVec(vec);
//     auto iter = std::find(vec.begin(), vec.end(), 9);
//     if (iter != vec.end()) {
//         std::cout << "找到了目标元素9" << "\n";
//     } else {
//         std::cout << "未找到目标元素9" << "\n";
//     }
// }