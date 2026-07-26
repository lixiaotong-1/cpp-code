// 在排序数组中查找元素的第一个和最后一个位置
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (target == nums[mid]) {
			return mid;
		}
		if (nums[mid] >= nums[left]) {
			if (target < nums[mid] && target >= nums[left]) {
				right = mid - 1;
			} else if (target > nums[mid] || target < nums[left]) {
				left = mid + 1;
			}
		} else {
			if (target > nums[mid] && target <= nums[right]) {
				left = mid + 1;
			} else if (target <= nums[mid] || target > nums[right]) {
				right = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int res = search(nums, 0);
	std::cout << res << "\n";
	res = search(nums, 3);
	std::cout << res << "\n";
	nums = {1};
	res = search(nums, 0);
	std::cout << res << "\n";
	nums = {3, 1};
	res = search(nums, 1);
	std::cout << res << "\n";
}