// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
#include <vector>
#include <iostream>

std::vector<int> cur_res;
std::vector<std::vector<int>> res;
std::vector<bool> visited;
void backtrace(std::vector<int>& nums, int n, std::vector<bool>& visited) {
    if (cur_res.size() == n) {
        res.push_back(cur_res);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        cur_res.push_back(nums[i]);
        visited[i] = true;
        backtrace(nums, n, visited);
        visited[i] = false;
        cur_res.pop_back();
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<bool> visited(n, false);
    backtrace(nums, nums.size(), visited);
    return res;
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::vector<std::vector<int>> res = permute(vec);
    for (const auto& vec: res) {
        for (const auto& num: vec) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}