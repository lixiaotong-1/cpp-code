// 通过 ACM 模式，写出选择排序代码示例，并能说明不稳定性与复杂度。
#include <iostream>
#include <vector>

void swapnum(std::vector<int>& arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void selectSort(std::vector<int>& arr) {
	int sz = arr.size();
	for (int i = 0; i < sz - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < sz; ++j) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		swapnum(arr, i, minIdx);
	}
}

int main()
{
	std::vector<int> nums = {10, 40, 6, 0, -3, 95, 4, 6, 90, 50};
	int sz = nums.size();
	selectSort(nums);
	for (int i = 0; i < sz; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
    return 0;
}