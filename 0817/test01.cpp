// 题目1：计算并输出当前时间与过去某个时间点的差异
// 要求：编写一个 C++ 程序，该程序计算并输出从程序开始执行到现在所经过的时间（以秒为单位）。
// 验收标准：
// 1. 程序应使用 std::chrono::high_resolution_clock 来获取开始和结束的时间点。
// 2. 程序应能正确计算两个时间点之间的差异，并将结果转换为秒数。
// 3. 程序应输出从开始执行到现在所经过的时间（秒）。
// #include <iostream>
// #include <chrono>
// #include <thread>

// long long getDuration() {
//     auto start = std::chrono::high_resolution_clock::now();
//     std::this_thread::sleep_for(std::chrono::seconds(5));
//     auto end = std::chrono::high_resolution_clock::now();
//     return std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
// }

// int main() {
//     std::cout << "开始计时...\n";
//     long long sec = getDuration();
//     std::cout << "经过时间：" << sec << " 秒\n";
//     return 0;
// }

// 题目2：比较两种时钟的精度
// 要求：编写一个 C++ 程序，该程序分别使用 std::chrono::system_clock 和 std::chrono::steady_clock 获取当前时间点，
// 并计算连续获取两个时间点之间差异的标准差（为简化，可只获取少数几个样本点进行比较）。
// 注意：由于实际中计算标准差需要多个样本点，且此题目的重点在于理解不同时钟的精度差异，
// 因此可以简化处理，只获取少量样本点进行比较，并说明这种方法的局限性。
// 验收标准：
// 1. 程序应能分别使用 system_clock 和 steady_clock 获取时间点
// #include <iostream>
// #include <chrono>
// #include <thread>
// #include <vector>

// double calStd(const std::vector<double>& samples) {
//     double sum = 0;
//     int sz = samples.size();
//     if (sz == 1) {
//         return 0;
//     }
//     for (const double& d: samples) {
//         sum += d;
//     }
//     double mean = sum / sz;
//     double stdsum = 0;
//     for (const double& d: samples) {
//         stdsum += (d - mean) * (d - mean);
//     }
//     return std::sqrt(stdsum / (sz - 1));
// }

// int main() {
//     std::vector<double> smp1;
//     std::vector<double> smp2;
//     int sample_cnt = 200;
//     for (int i = 0; i < sample_cnt; ++i) {
//         auto time1 = std::chrono::system_clock::now();
//         auto time2 = std::chrono::system_clock::now();
//         long long diff = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
//         smp1.push_back(diff);

//         auto time3 = std::chrono::steady_clock::now();
//         auto time4 = std::chrono::steady_clock::now();
//         long long diff1 = std::chrono::duration_cast<std::chrono::microseconds>(time4 - time3).count();
//         smp2.push_back(diff1);
//     }
//     double stdsum1 = calStd(smp1);
//     double stdsum2 = calStd(smp2);
//     std::cout << "样本数：" << sample_cnt << "，单位：微秒\n";
//     std::cout << "system_clock 标准差：" << stdsum1 << "\n";
//     std::cout << "steady_clock 标准差：" << stdsum2 << "\n";

//     std::cout << "\n=== 方法局限性 ===\n";
//     std::cout << "1.样本数量少，统计结果仅作参考；\n";
//     std::cout << "2.两次now()调用本身存在系统调用与CPU调度开销，不完全代表时钟硬件精度；\n";
//     std::cout << "3.system_clock是墙上时钟，可能被NTP校时回拨，不适合计算时间间隔；\n";
//     std::cout << "4.steady_clock为单调时钟，专门用于时间差测量。\n";
// }

// 题目3：格式化输出当前时间
// 要求：编写一个 C++ 程序，获取当前的时间点，并将其转换为可读的字符串形式，比如2024-02-23 12:12:43.
// 验收标准：
// 1. 程序应使用 std::chrono::system_clock 或其他适当的时钟来获取当前时间。
// 2. 程序应能正确地将时间点转换为可读的日期时间字符串。
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    auto cur_time = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(cur_time);
    std::cout << ctime(&time) << "\n";
    std::tm localtime = *std::localtime(&time);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &localtime);
    std::cout << buf << "\n";
}