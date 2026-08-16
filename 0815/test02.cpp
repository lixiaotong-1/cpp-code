// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，
// 使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
#include <iostream>
#include <vector>
#include <climits>

int minPathSum(std::vector<std::vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < n; ++j) {
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
    std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	int res = minPathSum(grid);
	std::cout << res << "\n";
    return 0;
}