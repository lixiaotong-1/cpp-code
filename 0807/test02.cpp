// 题目1：map的基本操作
// 要求：编写一个C++程序，定义一个std::map<std::string, int>对象，
// 并向其中插入几个键值对（例如："apple" -> 100, "banana" -> 200, "cherry" -> 300）。然后，遍历该map，并打印出每个键值对。
// 验收标准：
// a. 程序能够正确定义并初始化std::map<std::string, int>对象。
// b. 程序能够使用insert()方法向map中插入键值对。
// c. 程序能够使用迭代器或范围for循环遍历map，并打印出每个键值对。
// #include <iostream>
// #include <map>
// #include <string>

// int main() {
//     std::map<std::string, int> map;
//     map.insert({"apple", 100});
//     map.insert({"banana", 200});
//     map.insert({"cherry", 300});
//     for (const auto& item: map) {
//         std::cout << item.first << ", " << item.second << "\n";
//     }
// }

// 题目2：unordered_map的查找与修改
// 要求：编写一个C++函数，该函数接收一个std::unordered_map<std::string, int>&（无序映射的引用）和一个字符串key作为参数。
// 如果key存在于unordered_map中，则将其对应的值增加10；如果不存在，则插入该键值对，其中键为key，值为10。
// 验收标准：
// a. 函数能够正确接收std::unordered_map<std::string, int>的引用和一个字符串作为参数。
// b. 如果key存在于unordered_map中，函数能够将其对应的值增加10。
// c. 如果key不存在于unordered_map中，函数能够插入新的键值对。
// d. 调用该函数后，原unordered_map的内容应被正确修改。
// #include <iostream>
// #include <unordered_map>
// #include <string>

// void modifyMap(std::unordered_map<std::string, int>& map, std::string key) {
//     if (map.find(key) != map.end()) {
//         map[key] += 10;
//     } else {
//         map[key] = 10;
//     }
// }

// int main() {
//     std::unordered_map<std::string, int> map;
//     map.insert({"apple", 100});
//     map.insert({"banana", 200});
//     map.insert({"cherry", 300});
//     modifyMap(map, "banana");
//     modifyMap(map, "orange");
//     for (auto iter = map.begin(); iter != map.end(); ++iter) {
//         std::cout << iter->first << ", " << iter->second << "\n";
//     }
// }

// 题目3：map与unordered_map的性能比较
// 要求（可选，更高级）：编写一个C++程序，分别使用std::map和std::unordered_map存储大量（例如100,000个）随机生成的键值对，
// 并测量向两个容器中插入元素、查找元素和遍历元素所需的时间。
// 验收标准：
// a. 程序能够生成大量随机键值对。
// b. 程序能够分别使用std::map和std::unordered_map存储这些键值对。
// c. 程序能够测量并打印出向两个容器中插入元素、查找元素和遍历元素所需的时间。
// d. 程序的分析应显示unordered_map在查找和插入操作上的性能优势（通常），以及map在遍历（尤其是顺序遍历）上的优势（如果适用）。
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <chrono>
#include <random>

int main() {
    std::unordered_map<int, int> unmap;
    std::map<int, int> map;
    std::srand(std::time(nullptr));
    std::vector<std::pair<int, int>> vec;
    
    for (int i = 0; i < 100000; ++i) {
        int v1 = rand();
        int v2 = rand();
        vec.emplace_back(v1, v2);
    }
    auto start = std::chrono::high_resolution_clock::now();
    // 插入
    for (const auto& data: vec) {
        map.insert(data);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto map_insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "map 插入用时" << map_insert_time.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    // 查找
    for (const auto& data: vec) {
        auto iter = map.find(data.first);
        (void)iter;
    }
    end = std::chrono::high_resolution_clock::now();
    auto map_find_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "map 查找用时" << map_find_time.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    // 遍历
    int longsum = 0;
    for (const auto& data: map) {
        int v2 = data.second;
        longsum += v2;
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << longsum << "\n";
    auto map_iter_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "map 遍历用时" << map_iter_time.count() << "\n";

    std::cout << "============================" << "\n";

    start = std::chrono::high_resolution_clock::now();
    // 插入
    for (const auto& data: vec) {
        unmap.insert(data);
    }
    end = std::chrono::high_resolution_clock::now();
    auto unmap_insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "unmap 插入用时" << unmap_insert_time.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    // 查找
    for (const auto& data: vec) {
        auto iter = unmap.find(data.first);
        (void)iter;
    }
    end = std::chrono::high_resolution_clock::now();
    auto unmap_find_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "unmap 查找用时" << unmap_find_time.count() << "\n";

    start = std::chrono::high_resolution_clock::now();
    // 遍历
    longsum = 0;
    for (const auto& data: unmap) {
        int v2 = data.second;
        longsum += v2;
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << longsum << "\n";
    auto unmap_iter_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "unmap 遍历用时" << unmap_iter_time.count() << "\n";
}