// 通过 ACM 模式，写出冒泡排序（含提前终止）代码示例，并能说明其原理与最好/最坏复杂度。
#include <iostream>
#include <vector>

void swapnum(std::vector<int>& arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void bubbleSort(std::vector<int>& arr) {
	int len = arr.size();
	bool isChanged = true;
	for (int i = 0; i < len - 1 && isChanged; ++i) {
		isChanged = false;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swapnum(arr, j, j + 1);
				isChanged = true;
			}
		}
	}
}

int main()
{
	std::vector<int> nums = {10, 40, 6, 0, -3, 95, 4, 6, 90, 50};
	int sz = nums.size();
	bubbleSort(nums);
	for (int i = 0; i < sz; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
    return 0;
}