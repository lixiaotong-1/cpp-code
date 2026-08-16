// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
// 这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
#include <iostream>
#include <vector>
#include <climits>

int rob(std::vector<int>& nums) {
	int n = nums.size();
	if (n == 1) {
		return nums[0];
	}
	if (n == 2) {
		return std::max(nums[0], nums[1]);
	}
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	// 第一个不考虑，最后一个考虑，第二个开始可能偷了也可能没偷
	dp[1][0] = 0;
	dp[1][1] = nums[1];
	for (int i = 2; i < n; ++i) {
		dp[i][1] = dp[i - 1][0] + nums[i];
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
	}
	int max_ret = std::max(dp[n - 1][0], dp[n - 1][1]);
	// 第一个考虑，最后一个不考虑
	dp[0][0] = 0;
	dp[0][1] = nums[0];
	for (int i = 1; i < n - 1; ++i) {
		dp[i][1] = dp[i - 1][0] + nums[i];
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
	}
	int max_ret1 = std::max(dp[n - 2][0], dp[n - 2][1]);
	return std::max(max_ret1, max_ret);
}


int main() {
    std::vector<int> nums = {1, 3, 2, 1};
	int res = rob(nums);
	std::cout << res << "\n";
    return 0;
}