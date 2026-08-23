// 题目1：使用std::atomic实现无锁计数器
// 要求：编写一个C++程序，使用std::atomic<int>来实现一个无锁计数器。
// 创建多个线程，每个线程都对这个计数器进行一定数量的增加操作。最后，验证计数器的值是否与预期相符。
// 验收标准：
// 1. 程序能够正确创建并启动多个线程。
// 2. 每个线程都使用std::atomic<int>提供的原子操作来增加计数器的值。
// 3. 最终计数器的值应与所有线程增加的总数一致。
#include <iostream>
#include <thread>
#include <atomic>
std::atomic<int> cnt{0};

void increment(int times) {
    for (int i = 0; i < times; ++i) {
        ++cnt;
    }
}

int main() {
    const int times = 300;
    std::thread t1(increment, times);
    std::thread t2(increment, times);
    std::thread t3(increment, times);
    std::thread t4(increment, times);

    if (t1.joinable()) {
        t1.join();
    }
    if (t2.joinable()) {
        t2.join();
    }
    if (t3.joinable()) {
        t3.join();
    }
    if (t4.joinable()) {
        t4.join();
    }
    std::cout << "cnt = " << cnt << "\n";
}