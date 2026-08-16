// 你是一个专业的小偷，计划偷窃沿街的房屋。
// 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，
// 一夜之内能够偷窃到的最高金额。
#include <iostream>
#include <vector>
#include <climits>

int rob(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	dp[0][0] = 0;
	dp[0][1] = nums[0];
	for (int i = 1; i < n; ++i) {
		dp[i][1] = dp[i - 1][0] + nums[i];
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
	}
	int max_ret = std::max(dp[n - 1][0], dp[n - 1][1]);
	return max_ret;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
	int res = rob(nums);
	std::cout << res << "\n";
    return 0;
}