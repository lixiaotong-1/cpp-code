// 通过 ACM 模式，写出希尔排序代码示例，并能说明不稳定性与复杂度。
#include <iostream>
#include <vector>

void sortArray(std::vector<int>& arr) {
	for (int gap = arr.size() / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i < arr.size(); ++i) {
			int tmp = arr[i];
			int j = i;
			while (j - gap >= 0 && tmp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = tmp;
		}
	}
}

int main()
{
	std::vector<int> nums = {10, 40, 6, 0, -3, 95, 4, 6, 90, 50};
	int sz = nums.size();
	sortArray(nums);
	for (int i = 0; i < sz; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
    return 0;
}