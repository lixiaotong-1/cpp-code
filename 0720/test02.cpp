// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
// 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法。
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] > target) {
			right = mid - 1;
		} else if (nums[mid] < target) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return right + 1;
}

int main()
{
	std::vector<int> nums = {1, 3, 5, 6};
	int res = searchInsert(nums, 2);
	std::cout << res << "\n";
}