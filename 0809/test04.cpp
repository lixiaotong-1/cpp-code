// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
// 只使用数字1到9
// 每个数字 最多使用一次 
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> cur_res;
int cur_sum = 0;

void backtrace(int k, int n, int start) {
    if (cur_sum > n || cur_res.size() > k) {
        return;
    }
    if (cur_sum == n && cur_res.size() == k) {
        res.push_back(cur_res);
    }
    // 9 - i + 1 >= k - cur_res.size();
    for (int i = start; i <= 10 + cur_res.size() - k; ++i) {
        cur_sum += i;
        cur_res.push_back(i);
        backtrace(k, n, i + 1);
        cur_res.pop_back();
        cur_sum -= i;
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    backtrace(k, n, 1);
    return res;
}

int main() {
    int k = 3, n = 9;
    auto res = combinationSum3(k, n);
    for (const auto& vec: res) {
        for (const auto& num: vec) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}