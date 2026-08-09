// 题目1：set的基本操作
// 要求：编写一个C++程序，定义一个std::set<int>对象，并向其中插入几个整数（例如：1, 3, 5, 7, 9）。然后，遍历该set，并打印出每个元素。
// 验收标准：
// 1. 程序能够正确定义并初始化std::set<int>对象。
// 2. 程序能够使用insert()方法向set中插入元素。
// 3. 程序能够使用迭代器或范围for循环遍历set，并打印出每个元素。
// 打印的元素应按升序排列。
// #include <iostream>
// #include <set>

// int main() {
//     std::set<int> st;
//     for (int i = 0; i <= 4; ++i) {
//         st.insert(2 * i + 1);
//     }
//     for (const auto& num: st) {
//         std::cout << num << " ";
//     }
//     std::cout << "\n";
// }


// 题目2：unordered_set的查找与删除
// 要求：编写一个C++函数，该函数接收一个std::unordered_set<std::string>&（无序集合的引用）和一个字符串key作为参数。
// 如果key存在于unordered_set中，则删除该元素并返回true；如果不存在，则返回false。
// 验收标准：
// 1. 函数能够正确接收std::unordered_set<std::string>的引用和一个字符串作为参数。
// 2. 如果key存在于unordered_set中，函数能够删除该元素并返回true。
// 3. 如果key不存在于unordered_set中，函数应返回false。
// 4. 调用该函数后，原unordered_set的内容应被正确修改。
// #include <iostream>
// #include <unordered_set>

// bool search(std::unordered_set<std::string>& unset, const std::string& key) {
//     if (unset.find(key) != unset.end()) {
//         return true;
//     } else {
//         return false;
//     }
// }

// int main() {
//     std::unordered_set<std::string> set;
//     set.insert("apple");
//     set.insert("banana");
//     set.insert("cherry");
//     set.insert("watermelon");
//     bool isfind = search(set, "apple");
//     std::cout << isfind << "\n";
//     isfind = search(set, "key");
//     std::cout << isfind << "\n";
// }

// 题目3：set与unordered_set的性能比较（可选，更高级）
// 要求（可选）：编写一个C++程序，分别使用std::set<int>和std::unordered_set<int>存储大量（例如100,000个）随机生成的整数，
// 并测量向两个容器中插入元素、查找元素和遍历元素所需的时间。
// 验收标准：
// 1. 程序能够生成大量随机整数。
// 2. 程序能够分别使用std::set<int>和std::unordered_set<int>存储这些整数。
// 3. 程序能够测量并打印出向两个容器中插入元素、查找元素和遍历元素所需的时间。
// 4. 程序的分析应显示unordered_set在查找和插入操作上的性能优势（通常），以及set在遍历（尤其是顺序遍历）上的特点（如果适用）。
// 注意，由于unordered_set的遍历顺序是不确定的，这里的“遍历”更多是指遍历过程的执行时间，而非遍历结果的顺序。
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <chrono>
#include <random>

int main() {
    std::unordered_set<int> unset;
    std::set<int> set;
    std::vector<int> vec;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 100000; ++i) {
        int num = rand();
        vec.push_back(num);
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    for (const auto& num: vec) {
        set.insert(num);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto set_insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "set insert time: " << set_insert_time.count() << "\n";

    start_time = std::chrono::high_resolution_clock::now();
    for (const auto& num: vec) {
        auto iter = set.find(num);
        (void)iter;
    }
    end_time = std::chrono::high_resolution_clock::now();
    auto set_find_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "set find time: " << set_find_time.count() << "\n";

    start_time = std::chrono::high_resolution_clock::now();
    long long sum = 0;
    for (const auto& num: set) {
        sum += num;
    }
    end_time = std::chrono::high_resolution_clock::now();
    auto set_iter_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << sum << "\n";
    std::cout << "set iter time: " << set_iter_time.count() << "\n";

    std::cout << "==============================" << "\n";

    start_time = std::chrono::high_resolution_clock::now();
    for (const auto& num: vec) {
        unset.insert(num);
    }
    end_time = std::chrono::high_resolution_clock::now();
    auto unset_insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "unordered_set insert time: " << unset_insert_time.count() << "\n";

    start_time = std::chrono::high_resolution_clock::now();
    for (const auto& num: vec) {
        auto iter = unset.find(num);
        (void)iter;
    }
    end_time = std::chrono::high_resolution_clock::now();
    auto unset_find_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "unordered_set find time: " << unset_find_time.count() << "\n";

    start_time = std::chrono::high_resolution_clock::now();
    sum = 0;
    for (const auto& num: unset) {
        sum += num;
    }
    end_time = std::chrono::high_resolution_clock::now();
    auto unset_iter_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << sum << "\n";
    std::cout << "unordered_set iter time: " << unset_iter_time.count() << "\n";
}