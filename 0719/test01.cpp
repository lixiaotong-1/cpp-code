// 在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。
// 请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数。
#include <iostream>
#include <vector>

int count = 0;

void swap(std::vector<int>& nums, int left, int right) {
	int tmp = nums[left];
	nums[left] = nums[right];
	nums[right] = tmp;
}

void merge(std::vector<int>& nums, int left, int mid, int right) {
	std::vector<int> vec(right - left + 1);
	int low = left;
	int high = mid + 1;
	int idx = 0;
	while (low <= mid && high <= right) {
		if (nums[low] <= nums[high]) {
			vec[idx++] = nums[low++];
		} else {
			count += mid - low + 1;
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
	if (left >= right) return ;
	int mid = left + ((right - left) >> 1);
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

int reversePairs(std::vector<int>& record) {
	if (record.size() < 2) return 0;
	mergeSort(record, 0, record.size() - 1);
	return count;
}

int main()
{
	std::vector<int> nums = {9, 7, 5, 4, 6};
	int res = reversePairs(nums);
	std::cout << res << "\n";
	for (int a : nums) {
		std::cout << a << " ";
	}
}