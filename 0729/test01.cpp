// 题目1：list的基本操作
// 要求：编写一个C++程序，定义一个std::list<int>对象，并向其中插入几个整数（例如：1, 3, 5, 7, 9）。然后，遍历该list，并打印出每个元素。
// 验收标准：
// 1. 程序能够正确定义并初始化std::list<int>对象。
// 2. 程序能够使用push_back()或emplace_back()方法向list中插入元素。
// 3. 程序能够使用迭代器或范围for循环遍历list，并打印出每个元素。
// #include <iostream>
// #include <list>

// int main() {
//     std::list<int> lst;
//     for (int i = 0; i < 5; ++i) {
//         lst.push_back(i * 2 + 1);
//     }
//     for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << "\n";
// }

// 题目2：list的插入与删除
// 要求：编写一个C++函数，该函数接收一个std::list<int>&（列表的引用）和两个整数value与position作为参数。
// 在position指定的位置（从0开始计数，若position超出当前列表长度，则在末尾插入）插入value。然后，删除列表中第一个出现的偶数元素（如果存在）。
// 验收标准：
// 1. 函数能够正确接收std::list<int>的引用和两个整数作为参数。
// 2. 函数能够在指定位置插入value。
// 3. 函数能够删除列表中第一个出现的偶数元素（如果存在）。
// 4. 调用该函数后，原list的内容应被正确修改。
// #include <iostream>
// #include <list>
// void modifyList(std::list<int>& lst, int value, int position) {
//     auto iter = lst.begin();
//     for (int i = 0; i < position && i < lst.size(); ++i) {
//         ++iter;
//     }
//     lst.insert(iter, value);
//     for (iter = lst.begin(); iter != lst.end(); ++iter) {
//         if (*iter % 2 == 0) {
//             iter = lst.erase(iter);
//             break;
//         }
//     }
// }

// int main() {
//     std::list<int> lst = {1 ,3, 5, 7, 9};
//     modifyList(lst, 10, 3);
//     for (const auto& i: lst) {
//         std::cout << i << " ";
//     }
//     std::cout << "\n";

//     lst = {2, 4, 6, 8, 10};
//     modifyList(lst, 9, 3);
//     for (const auto& i: lst) {
//         std::cout << i << " ";
//     }
//     std::cout << "\n";
// }

// 题目3：list的排序与反转
// 要求：编写一个C++程序，定义一个std::list<int>对象，并向其中插入几个未排序的整数（例如：9, 3, 5, 1, 7）。
// 然后，对list进行排序，并打印排序后的结果。接着，反转list中的元素顺序，并打印反转后的结果。
// 验收标准：
// 1. 程序能够正确定义并初始化std::list<int>对象，并向其中插入未排序的整数。
// 2. 程序能够使用sort()成员函数对list中的元素进行排序。
// 3. 程序能够使用reverse()成员函数反转list中元素的顺序。
// 4. 程序能够打印出排序和反转后的list内容。
#include <iostream>
#include <list>

void printList(const std::list<int>& lst) {
    for (const int& n: lst) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main() {
    std::list<int> lst = {9, 3, 5, 1, 7};
    lst.sort();
    printList(lst);
    lst.reverse();
    printList(lst);
    return 0;
}