// 搜索旋转排序数组 II
#include <iostream>
#include <vector>


bool search(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (target == nums[mid]) {
			return true;
		}
		if (nums[mid] == nums[left]) {
			++left;
			continue;
		}
		if (nums[mid] > nums[left]) {
			if (target >= nums[left] && target < nums[mid]) {
				right = mid - 1;
			} else if (target < nums[left] || target >= nums[mid]) {
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
	return false;
}

int main() {
	std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
	int res = search(nums, 0);
	std::cout << res << "\n";
	res = search(nums, 3);
	std::cout << res << "\n";
}