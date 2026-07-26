// 找到第一个大于或最后一个小于目标值的索引
#include <iostream>
#include <vector>

int lowerBound(std::vector<int>& nums, int left, int right, int target) {
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] > target) {
			if (mid == 0 || nums[mid - 1] <= target) {
				return mid;
			} else {
				right = mid - 1;
			}
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int upperBound(std::vector<int>& nums, int left, int right, int target) {
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] < target) {
			if (mid == right || nums[mid + 1] >= target) {
				return mid;
			} else {
				left = mid + 1;
			}
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	std::vector<int> nums = {1, 3, 5, 5, 6, 6, 8, 9, 11};
	int lower = lowerBound(nums, 0, nums.size() - 1, 7);
	int upper = upperBound(nums, 0, nums.size() - 1, 7);
	std::cout << lower << "\n";
	std::cout << upper << "\n";
}