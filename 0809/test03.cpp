// 给定一个候选人编号的集合 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次 。
// 注意：解集不能包含重复的组合。 
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> cur_res;
int cur_sum = 0;

void backtrace(std::vector<int>& candidates, int target, int start_idx) {
    if (cur_sum > target) {
        return;
    }
    if (cur_sum == target) {
        res.push_back(cur_res);
        return;
    }
    for (int i = start_idx; i < candidates.size(); ++i) {
        if (i > start_idx && candidates[i] == candidates[i - 1]) {
            continue;
        }
        int cur_num = candidates[i];
        cur_res.push_back(cur_num);
        cur_sum += cur_num;
        backtrace(candidates, target, i + 1);
        cur_sum -= cur_num;
        cur_res.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    backtrace(candidates, target, 0);
    return res;
}

int main() {
    std::vector<int> candidates = {10, 1, 2, 7, 1, 6, 5};
    auto res = combinationSum2(candidates, 8);
    for (const auto& vec: res) {
        for (const auto& num: vec) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}