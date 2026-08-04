// 题目1：队列的基本操作
// 要求：编写一个C++程序，定义一个std::queue<int>对象，并向其中添加5个整数（例如1, 2, 3, 4, 5）。
// 然后，使用循环结构移除并打印队列中的所有元素，直到队列为空。
// 验收标准：
// 1. 程序能够正确定义并初始化std::queue<int>对象。
// 2. 程序能够使用push()方法向队列中添加元素。
// 3. 程序能够使用循环结构和pop()、front()方法移除并打印队列中的所有元素，直到队列为空。
// 4. 程序的输出应为：1 2 3 4 5。
// #include <iostream>
// #include <queue>

// int main() {
//     std::queue<int> q;
//     for (int i = 1; i <= 5; ++i) {
//         q.push(i);
//     }
//     while (!q.empty()) {
//         int top = q.front();
//         std::cout << top << " ";
//         q.pop();
//     }
//     std::cout << "\n";
// }

// 题目2：队列的大小与空检查
// 要求：编写一个C++程序，该程序首先定义一个空的std::queue<int>对象，并通过一系列操作（添加和移除元素）来修改队列。
// 在每个操作后，程序应检查队列是否为空，并打印队列的当前大小。
// 验收标准：
// 1. 程序能够正确定义并初始化空的std::queue<int>对象。
// 2. 程序能够通过push()方法向队列中添加元素，并通过pop()方法从队列中移除元素。
// 3. 在每次添加或移除元素后，程序能够使用empty()方法检查队列是否为空，并使用size()方法打印队列的当前大小。
// 4. 程序的输出应反映队列状态的变化，包括队列的大小和是否为空。
#include <iostream>
#include <queue>

void printSize(const std::queue<int>& q) {
    if (!q.empty()) {
        std::cout << "size = " << q.size() << "\n";
    } else {
        std::cout << "队列为空" << "\n";
    }
}

int main() {
    std::queue<int> q;
    q.push(1);
    printSize(q);
    q.push(2);
    printSize(q);
    q.pop();
    printSize(q);
    q.pop();
    printSize(q);
    // q.pop(); // 段错误
}
