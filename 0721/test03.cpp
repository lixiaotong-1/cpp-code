// 在排序数组中查找元素的第一个和最后一个位置
#include <iostream>
#include <vector>

int lowerBound(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] >= target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int upperBound(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] <= target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return right;
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
	int lower = lowerBound(nums, target);
	int upper = upperBound(nums, target);
	if (upper < lower) {
		return {-1, -1};
	}
	return {lower, upper};
}

int main() {
	std::vector<int> nums = {5, 7, 7, 8, 8, 10};
	std::vector<int> res = searchRange(nums, 8);
	std::cout << res[0] << ", " << res[1] << "\n";
	
	nums = {5, 7, 7, 8, 8, 10};
	res = searchRange(nums, 6);
	std::cout << res[0] << ", " << res[1] << "\n";
	
	nums = {};
	res = searchRange(nums, 0);
	std::cout << res[0] << ", " << res[1] << "\n";
}