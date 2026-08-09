// 题目1：priority_queue的基本操作
// 要求：编写一个C++程序，定义一个std::priority_queue<int>对象，并向其中插入几个整数（例如：3, 1, 4, 1, 5, 9, 2）。
// 然后，依次弹出并打印priority_queue中的最大元素，直到它为空。
// 验收标准：
// 1. 程序能够正确定义并初始化std::priority_queue<int>对象。
// 2. 程序能够使用push()方法向priority_queue中插入元素。
// 3. 程序能够使用pop()和top()方法弹出并打印priority_queue中的最大元素，直到其为空。
// 4. 打印的元素应按降序排列。
// #include <iostream>
// #include <queue>
// #include <vector>

// int main () {
//     std::priority_queue<int> q;
//     std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2};
//     for (const int& i: vec) {
//         q.push(i);
//     }
//     while (!q.empty()) {
//         int top = q.top();
//         q.pop();
//         std::cout << top << " ";
//     }
//     std::cout << "\n";
// }

// 题目2：自定义比较器的priority_queue
// 要求：编写一个C++程序，定义一个使用自定义比较器的std::priority_queue<int, std::vector<int>, std::greater<int>>对象（即一个最小堆）。
// 向其中插入几个整数（例如：9, 3, 5, 1, 7, 2, 4）。然后，依次弹出并打印priority_queue中的最小元素，直到它为空。
// 验收标准：
// 1. 程序能够正确定义并初始化使用自定义比较器的std::priority_queue<int, std::vector<int>, std::greater<int>>对象。
// 2. 程序能够使用push()方法向priority_queue中插入元素。
// 3. 程序能够使用pop()和top()方法弹出并打印priority_queue中的最小元素，直到其为空。
// 4. 打印的元素应按升序排列。
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    std::vector<int> vec = {9, 3, 5, 1, 7, 2, 4};
    for (const int& i: vec) {
        q.push(i);
    }
    while (!q.empty()) {
        int top = q.top();
        q.pop();
        std::cout << top << " ";
    }
    std::cout << "\n";
}