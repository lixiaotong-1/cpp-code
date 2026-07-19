// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 
// 我们就将 (i, j) 称作一个重要翻转对。
// 你需要返回给定数组中的重要翻转对的数量。
#include <iostream>
#include <vector>
int count = 0;

void merge(std::vector<int>& nums, int left, int mid, int right) {
	int low = left, high = mid + 1;
	std::vector<int> vec(right - left + 1);
	int idx = 0;
	while (low <= mid && high <= right) {
		if (static_cast<long long>(nums[low]) > 2LL * nums[high]) {
			count += mid - low + 1;
			++high;
		} else {
			++low;
		}
	}
	low = left;
	high = mid + 1;
	while (low <= mid && high <= right) {
		if (nums[low] <= nums[high]) {
			vec[idx++] = nums[low++];
		} else {
			vec[idx++] = nums[high++];
		}
	}
	while (low <= mid) {
		vec[idx++] = nums[low++];
	}
	while (high <= right) {
		vec[idx++] = nums[high++];
	}
	for (int i = 0; i < vec.size(); ++i) {
		nums[i + left] = vec[i];
	}
}

void mergeSort(std::vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int mid = left + ((right - left) / 2);
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

int reversePairs(std::vector<int>& nums) {
	if (nums.size() < 2) {
		return 0;
	}
	mergeSort(nums, 0, nums.size() - 1);
	return count;
}

int main()
{
	std::vector<int> nums = {2, 4, 3, 5, 1};
	int res = reversePairs(nums);
	std::cout << res << "\n";
	for (int a : nums) {
		std::cout << a << " ";
	}
}