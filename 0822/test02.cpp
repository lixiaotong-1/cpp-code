// 题目1：使用mutex保护共享数据
// 要求：编写一个C++程序，包含两个线程，一个生产者线程和一个消费者线程。
// 生产者线程生成整数并存入共享队列，消费者线程从队列中取出整数并打印。使用std::mutex保护队列的访问。
// 验收标准：
// 1. 程序能够正确创建并启动生产者和消费者线程。
// 2. 生产者线程和消费者线程能够正确地通过std::mutex同步访问共享队列。
// 3. 消费者线程能够打印出生产者线程生成的整数，且没有数据丢失或重复。
// #include <iostream>
// #include <thread>
// #include <queue>
// #include <mutex>
// #include <chrono>

// std::mutex mut;
// std::queue<int> q;

// void produce() {
//     for (int i = 0; i < 10; ++i) {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         mut.lock();
//         q.push(i + 1);
//         std::cout << "生产了" << i + 1 << "\n";
//         mut.unlock();
//     }
// }

// void consume() {
//     int cnt = 0;
//     while (cnt < 10) {
//         std::this_thread::sleep_for(std::chrono::microseconds(500));
//         mut.lock();
//         while (!q.empty()) {
//             int top = q.front();
//             std::cout << "消费了" << top << "\n";
//             q.pop();
//             ++cnt;
//         }
//         mut.unlock();
//     }
// }

// int main() {
//     std::thread t1(produce);
//     std::thread t2(consume);
//     if (t1.joinable()) {
//         t1.join();
//     }
//     if (t2.joinable()) {
//         t2.join();
//     }
// }

// 题目2：使用unique_lock和condition_variable实现等待/通知机制
// 要求：扩展题目1的程序，使用std::unique_lock和std::condition_variable来改进生产者-消费者模型。
// 当队列为空时，消费者线程应等待；当队列非空时，消费者线程应被唤醒并取出数据。
// 验收标准：
// 1. 程序能够使用std::unique_lock和std::condition_variable实现生产者和消费者之间的同步。
// 2. 消费者线程在队列为空时能够正确等待，并在有新数据时被唤醒。
// 3. 生产者线程在添加数据到队列后能够正确通知等待的消费者线程。

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex mut;
std::queue<int> q;
std::condition_variable cv;

void produce() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(mut);
        q.push(i + 1);
        std::cout << "生产了" << i + 1 << "\n";
        cv.notify_all();
    }
}

void consume() {
    int cnt = 0;
    while (cnt < 10) {
        std::unique_lock<std::mutex> lock(mut);
        cv.wait(lock, [&]() { return !q.empty(); });
        int val = q.front();
        q.pop();
        ++cnt;
        std::cout << "消费了" << val << "\n";
    }
}

int main() {
    std::thread t1(produce);
    std::thread t2(consume);
    if (t1.joinable()) {
        t1.join();
    }
    if (t2.joinable()) {
        t2.join();
    }
}