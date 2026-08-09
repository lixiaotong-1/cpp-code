// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
#include <vector>
#include <iostream>

std::vector<int> cur_res;
std::vector<std::vector<int>> res;
std::vector<bool> visited;

void backtrace(std::vector<int>& nums, int n, std::vector<bool> visited) {
    if (cur_res.size() == n) {
        res.push_back(cur_res);
        return;
    }
    for (int i = 0; i < n; ++i) {
        // 同一层的不能重复
        if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == false) {
            continue;
        }
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

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<bool> visited(n, false);
    backtrace(nums, n, visited);
    return res;
}

int main() {
    std::vector<int> vec = {1, 1, 2};
    std::vector<std::vector<int>> res = permuteUnique(vec);
    for (const auto& vec: res) {
        for (const auto& num: vec) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}