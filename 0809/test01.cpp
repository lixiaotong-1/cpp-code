// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 你可以按 任何顺序 返回答案。
#include <iostream>
#include <vector>

void backtrace(std::vector<std::vector<int>>& res, std::vector<int>& cur_res, int start, int k, int n) {
    if (cur_res.size() == k) {
        res.push_back(cur_res);
        return;
    }
    for (int i = start; i <= n + 1 + cur_res.size() - k; ++i) {
        cur_res.push_back(i);
        backtrace(res, cur_res, i + 1, k, n);
        cur_res.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> cur_res;
    backtrace(res, cur_res, 1, k, n);
    return res;
}

int main() {
    int n = 4, k = 2;
    std::vector<std::vector<int>> res = combine(n, k);
    for (const auto& i: res) {
        std::cout << i[0] << ", " << i[1] << "\n";
    }
}