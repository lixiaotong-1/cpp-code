// 通过 ACM 模式，写出选择排序代码示例，并能说明不稳定性与复杂度。
#include <iostream>
#include <vector>

void insertSort(std::vector<int>& arr) {
	int len = arr.size();
	for (int i = 1; i < len; ++i) {
		int tmp = arr[i];
        int j = i - 1;
		for (j = i - 1; j >= 0; --j) {
			if (arr[j] > tmp) {
                arr[j + 1] = arr[j];
                continue;
            }
            break;
		}
        arr[j + 1] = tmp;
	}
}

int main()
{
	std::vector<int> nums = {10, 40, 6, 0, -3, 95, 4, 6, 90, 50};
	int sz = nums.size();
	insertSort(nums);
	for (int i = 0; i < sz; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
    return 0;
}