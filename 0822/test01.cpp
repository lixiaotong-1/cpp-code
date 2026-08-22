// 题目1：使用std::thread创建多个线程，每个线程打印不同的信息
// 要求：编写一个C++程序，创建三个线程，每个线程分别打印“Hello from Thread 1”, “Hello from Thread 2”, “Hello from Thread 3”。
// 验收标准：
// 1. 程序能够正确创建并启动三个线程。
// 2. 每个线程打印出对应的消息。
// 3. 确保主线程在所有子线程完成后才结束（可以通过join()实现）。
// #include <iostream>
// #include <thread>

// std::mutex mut;

// void printId(int id) {
//     std::lock_guard<std::mutex> lock(mut);
//     std::cout << "Hello from Thread " << id << "\n";
// }

// int main() {
//     std::thread threads[3];
//     for (int i = 0; i < 3; ++i) {
//         threads[i] = std::thread(printId, i + 1);
//     }
//     for (int i = 0; i < 3; ++i) {
//         if (threads[i].joinable()) {
//             threads[i].join();
//         }
//     }
// }

// 题目2：使用std::mutex保护共享数据
// 要求：编写一个C++程序，其中包含一个共享整数counter和两个线程。这两个线程不断递增counter的值（每个线程递增10000次），并在所有递增操作完成后输出counter的最终值。
// 验收标准：
// 1. 程序能够正确创建并启动两个线程。
// 2. 使用std::mutex保护对counter的访问，确保不会出现竞态条件。
// 3. 最终输出的counter值应为20000（或接近，由于调度等原因可能略有差异）。
// #include <iostream>
// #include <thread>

// int count = 0;
// std::mutex mut;

// void increment() {
//     for (int i = 0; i < 10000; ++i) {
//         mut.lock();
//         ++count;
//         mut.unlock();
//     }
// }

// int main() {
//     std::thread t1(increment);
//     std::thread t2(increment);
//     if (t1.joinable()) {
//         t1.join();
//     }
//     if (t2.joinable()) {
//         t2.join();
//     }
//     std::cout << "count = " << count << "\n";
// }

// 题目3：使用std::condition_variable实现生产者-消费者模型
// 要求：编写一个C++程序，实现一个简单的生产者-消费者模型。生产者线程生成整数并放入队列中，消费者线程从队列中取出整数并打印。
// 使用std::mutex保护队列，使用std::condition_variable实现生产者和消费者之间的同步。
// 验收标准：
// 1. 程序能够正确创建并启动一个生产者线程和一个消费者线程。
// 2. 生产者线程能够生成整数并放入队列，消费者线程能够从队列中取出整数并打印。
// 3. 使用std::mutex和std::condition_variable确保线程安全，并正确同步生产者和消费者的操作。
// 4. 验证程序能够持续运行一段时间（例如，生产者生产10个整数，消费者消费这些整数），且没有数据丢失或重复打印的情况。
#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <chrono>

std::queue<int> q;
std::mutex mut;
std::condition_variable cv;

void produce() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(mut);
        std::cout << "生产了" << i + 1 << "\n";
        q.push(i + 1);
        cv.notify_one();
    }
    
}

void consume() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mut);
        while (q.empty()) {
            cv.wait(lock);
        }
        std::cout << "消费了" << q.front() << "\n";
        q.pop();
    }
}

int main() {
    std::thread t1(produce);
    std::thread t2(consume);
    t1.join();
    t2.join();
}