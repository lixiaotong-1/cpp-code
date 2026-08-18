// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同
// 或者等于 上一层结点下标 + 1 的两个结点。也就是说，
// 如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
#include <iostream>
#include <vector>
#include <climits>

// int minimumTotal(std::vector<std::vector<int>>& triangle) {
// 	int m = triangle.size();
// 	int n = triangle[m - 1].size();
// 	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(m, std::vector<int>(n, INT_MAX));
// 	dp[0][0] = triangle[0][0];
// 	for (int i = 1; i < m; ++i) {
// 		for (int j = 0; j < triangle[i].size(); ++j) {
// 			if (j < triangle[i - 1].size() && j >= 1) {
// 				dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
// 			} else if (j < 1) {
// 				dp[i][j] = dp[i - 1][j] + triangle[i][j];
// 			} else if (j >= triangle[i - 1].size()) {
//                 dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
//             }
// 		}
// 	}
// 	int res = INT_MAX;
// 	for (int j = 0; j < n; ++j) {
// 		res = std::min(res, dp[m - 1][j]);
// 	}
// 	return res;
// }

int minimumTotal(std::vector<std::vector<int>>& triangle) {
	int m = triangle.size();
	int n = triangle[m - 1].size();
	std::vector<int> dp(n, INT_MAX);
	dp[0] = triangle[0][0];
	for (int i = 1; i < m; ++i) {
		for (int j = i; j >= 0; --j) {
			if (j == i) {
				dp[j] = dp[j - 1] + triangle[i][j];
			} else if (j == 0) {
				dp[j] = dp[j] + triangle[i][j];
			} else {
				dp[j] = std::min(dp[j], dp[j - 1]) + triangle[i][j];
			}
		}
	}
	int res = INT_MAX;
	for (int i = 0; i < n; ++i) {
		res = std::min(res, dp[i]);
	}
	return res;
}

int main() {
    std::vector<std::vector<int>> vec = {{-1}, {-2, -3}};
	int res = minimumTotal(vec);
	std::cout << res << "\n";
    return 0;
}