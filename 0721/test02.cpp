// 寻找旋转排序数组中的最小值
#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		if (nums[left] < nums[right]) {
			return nums[left];
		}
		int mid = left + ((right - left) >> 1);
		if (nums[mid] >= nums[left]) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return nums[left];
}

int main() {
	std::vector<int> nums = {2, 1};
	int res = findMin(nums);
	std::cout << res << "\n";
}