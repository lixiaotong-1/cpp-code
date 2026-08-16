// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
// 设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
#include <iostream>
#include <vector>

// int maxProfit(std::vector<int>& prices) {
// 	int sz = prices.size();
// 	if (sz == 0) {
// 		return 0;
// 	}
// 	std::vector<std::vector<int>> dp(sz, std::vector<int>(2));
// 	dp[0][0] = 0;
// 	dp[0][1] = -prices[0];
// 	for (int i = 1; i < sz; ++i) {
// 		dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
// 		dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
// 	}
// 	return dp[sz - 1][0];
// }

//空间优化版本
// int maxProfit(std::vector<int>& prices) {
// 	int n = prices.size();
// 	if (n == 0) {
// 		return 0;
// 	}
// 	int prevProfit1 = 0; // 这一天不买
// 	int prevProfit2 = -prices[0]; // 这一天买了
// 	for (int i = 1; i < n; ++i) {
// 		int curProfit1 = std::max(prevProfit1, prevProfit2 + prices[i]);
// 		int curProfit2 = std::max(-prices[i], prevProfit2);
// 		prevProfit1 = curProfit1;
// 		prevProfit2 = curProfit2;
// 	}
// 	return prevProfit1;
// }

// 好理解的版本
int maxProfit(std::vector<int>& prices) {
	int n = prices.size();
	int min_price = INT_MAX;
	int max_profit = 0;
	for (int i = 0; i < n; ++i) {
		if (prices[i] < min_price) {
			min_price = prices[i];
		}
		max_profit = std::max(max_profit, prices[i] - min_price);
		
	}
	return max_profit;
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
	int res = maxProfit(prices);
	std::cout << res << "\n";
    return 0;
}