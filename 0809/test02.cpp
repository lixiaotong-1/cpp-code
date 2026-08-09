// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
// 找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
#include <iostream>
#include <vector>

void backtrace(std::vector<std::vector<int>>& res, std::vector<int>& cur_res, std::vector<int>& candidates, int target, int& cur_sum, int start) {
    if (cur_sum > target) {
        return;
    }
    if (cur_sum == target) {
        res.push_back(cur_res);
    }
    for (int i = start; i < candidates.size(); ++i) {
        int num = candidates[i];
        if (cur_sum + num > target) {
            continue;
        }
        cur_sum += num;
        cur_res.push_back(num);
        backtrace(res, cur_res, candidates, target, cur_sum, i);
        cur_res.pop_back();
        cur_sum -= num;
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> cur_res;
    int cur_sum = 0;
    sort(candidates.begin(), candidates.end());
    backtrace(res, cur_res, candidates, target, cur_sum, 0);
    return res;
}

int main() {
    std::vector<int> candidates = {2, 3, 6, 7};
    auto res = combinationSum(candidates, 7);
    for (const auto& vec: res) {
        for (const auto& num: vec) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}