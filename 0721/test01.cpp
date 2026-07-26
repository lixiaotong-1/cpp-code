// 给你一个满足下述两条属性的 m x n 整数矩阵：
// 每行中的整数从左到右按非严格递增顺序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
	int left = 0;
	int lenRow = matrix.size();
	int lenCol = matrix[0].size();
	int size = lenRow * lenCol;
	int right = size - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		int rowIdx = mid / lenCol;
		int colIdx = mid % lenCol;
		if (matrix[rowIdx][colIdx] == target) {
			return true;
		} else if (matrix[rowIdx][colIdx] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return false;
}

int main()
{
	std::vector<std::vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int res = searchMatrix(nums, 3);
	std::cout << res << "\n";
}