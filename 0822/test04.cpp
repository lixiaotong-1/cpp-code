// 使用 std::future 获取异步结果：
// 编写一个函数，模拟耗时操作（如计算斐波那契数列的第 n 项）。
// 使用 std::async 启动异步任务，并使用 std::future 获取结果。
// 打印结果并测量任务执行时间。
// #include <iostream>
// #include <thread>
// #include <future>
// #include <chrono>

// int fib(int n) {
//     if (n == 1 || n == 2) {
//         return 1;
//     }
//     return fib(n - 1) + fib(n - 2);
// }

// int main() {
//     int n = 10;
//     auto start = std::chrono::high_resolution_clock::now();
//     std::future<int> res = std::async(std::launch::async, fib, n);
//     int ans = res.get();
//     auto end = std::chrono::high_resolution_clock::now();
//     std::cout << "异步计算用时: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "\n";
//     std::cout << "fib(n) = " << ans << "\n";
// }

// 使用 std::packaged_task 包装任务：
// 编写一个函数，计算给定范围内的素数。
// 使用 std::packaged_task 将该函数包装为任务。
// 启动任务并使用 std::future 获取结果
// 打印素数列表。
// #include <iostream>
// #include <thread>
// #include <future>
// #include <cmath>
// #include <vector>
// #include <chrono>

// bool isPrime(int num) {
//     if (num == 1) {
//         return false;
//     }
//     if (num == 2) {
//         return true;
//     }
//     int mid = static_cast<int>(std::sqrt(num));
//     for (int i = 2; i <= mid; ++i) {
//         if (num % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// std::vector<int> printPrime(int n) {
//     std::vector<int> res;
//     for (int i = 2; i <= n; ++i) {
//         if (isPrime(i)) {
//             res.push_back(i);
//         }
//     }
//     return res;
// }

// int main() {
//     int n = 50;
//     std::packaged_task<std::vector<int>(int)> task(printPrime);
//     auto res = task.get_future();
//     std::thread t(std::move(task), n);
//     if (t.joinable()) {
//         t.join();
//     }
//     for (const auto item: res.get()) {
//         std::cout << item << "\n";
//     }
// }

// 使用 std::promise 设置异步结果：
// 编写一个函数，模拟异步下载。
// 使用 std::promise 在下载完成后设置结果。
// 在主线程中使用 std::future 获取下载结果并打印。
#include <iostream>
#include <thread>
#include <future>
#include <exception>
#include <string>
#include <chrono>

void download(std::promise<std::string> prom, bool flag) {
    try {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (!flag) {
            throw std::runtime_error("下载失败");
        }
        std::string s("下载成功");
        prom.set_value(s);
    } catch (const std::exception& e) {
        prom.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<std::string> prom;
    auto fut = prom.get_future();
    std::thread t(download, std::move(prom), false);
    t.join();
    try {
       std::cout << fut.get() << "\n";
    } catch(const std::exception& e) {
       std::cout << e.what() << "\n";
    }
}