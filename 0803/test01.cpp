// 题目1：双端队列的基本操作
// 要求：编写一个C++程序，定义一个std::deque<int>对象，并向其两端添加元素，直到包含以下序列：{1, 2, 3, 4, 5}。
// 然后，从两端依次移除元素，并打印每次移除后的deque内容，直到deque为空。
// 验收标准：
// 1. 程序能够正确定义并初始化std::deque<int>对象。
// 2. 程序能够使用push_front()和push_back()方法向deque两端添加元素。
// 3. 程序能够使用pop_front()和pop_back()方法从deque两端移除元素，并打印每次操作后的deque内容。
// 4. 程序的输出应反映deque内容的变化过程，直到为空。
// #include <iostream>
// #include <deque>

// void printDeque(const std::deque<int>& dq) {
//     for (auto iter = dq.begin(); iter != dq.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << "\n";
// }

// int main() {
//     std::deque<int> dq;
//     dq.push_back(3);
//     dq.push_back(4);
//     dq.push_back(5);
//     dq.push_front(2);
//     dq.push_front(1);
//     printDeque(dq);
//     dq.pop_back();
//     printDeque(dq);
//     dq.pop_back();
//     printDeque(dq);
//     dq.pop_back();
//     printDeque(dq);
//     dq.pop_front();
//     printDeque(dq);
//     dq.pop_front();
//     printDeque(dq);
// }


// 题目2：双端队列的遍历与访问
// 要求：编写一个C++程序，定义一个std::deque<int>对象，并通过循环或范围for循环遍历该deque，打印出其中的所有元素。
// 然后，使用at()方法访问并打印deque中索引为2的元素（假设deque至少包含3个元素）。
// 验收标准：
// 1. 程序能够正确定义并初始化std::deque<int>对象，并填充足够的元素以供访问。
// 2. 程序能够使用循环或范围for循环遍历deque，并打印出所有元素。
// 3. 程序能够使用at()方法正确访问并打印deque中指定索引的元素。
// #include <iostream>
// #include <deque>

// int main() {
//     std::deque<int> dq;
//     for (int i = 0; i < 5; ++i) {
//         dq.push_back(i + 1);
//     }
//     for (const auto& i: dq) {
//         std::cout << i << " ";
//     }
//     std::cout << "\n";
//     std::cout << "下标为2的元素为:" << dq.at(2) << "\n";
// }


// 题目3：双端队列的插入与元素修改
// 要求：编写一个C++函数，该函数接收一个std::deque<int>&（双端队列的引用）和一个整数n作为参数。
// 函数的任务是在deque的开头插入一个元素n，然后遍历deque，将所有元素的值加倍。
// 验收标准：
// 1. 函数能够正确接收std::deque<int>的引用和一个整数作为参数。
// 2. 函数能够在deque的开头插入元素n。
// 3. 函数能够遍历deque，并将所有元素的值加倍。
// 4. 调用该函数后，原deque的内容应被正确修改。
#include <iostream>
#include <deque>

void procDeque(std::deque<int>& dq, int n) {
    dq.push_front(n);
    for (auto& i: dq) {
        i *= 2;
    }
}

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};
    procDeque(dq, 0);
    for (const auto& i: dq) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}