// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
// 一旦你支付此费用，即可选择向上爬一个或者两个台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的最低花费。
#include <iostream>
#include <vector>
#include <climits>

int minCostClimbingStairs(std::vector<int>& cost) {
	// int sz = cost.size();
	// std::vector<int> ret(sz + 1, INT_MAX);
	// ret[0] = 0;
	// ret[1] = 0;
	// for (int i = 2; i <= sz; ++i) {
	//     ret[i] = std::min(ret[i - 1] + cost[i - 1], ret[i - 2] + cost[i - 2]);
	// }
	// return ret[sz];
	int sz = cost.size();
	int prev1 = 0, prev2 = 0;
	for (int i = 2; i <= sz; ++i) {
		int cur = std::min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
		prev2 = prev1;
		prev1 = cur;
	}
	return prev1;
}

int main() {
    std::vector<int> cost = {10, 15, 20};
	int res = minCostClimbingStairs(cost);
	std::cout << res << "\n";
    return 0;
}