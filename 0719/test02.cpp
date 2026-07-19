// 描述
// 输入一个非负整数数组numbers，把数组里所有数字拼接起来排成一个数，
// 打印能拼接出的所有数字中最小的一个。
// 例如输入数组[3，32，321]，则打印出这三个数字能排成的最小数字为321323。
// 1.输出结果可能非常大，所以你需要返回一个字符串而不是整数
// 2.拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
// 数据范围:
// 0<=len(numbers)<=100
#include <iostream>
#include <vector>
#include <string>

void swap(std::vector<std::string>& nums, int left, int right) {
	std::string tmp = nums[left];
	nums[left] = nums[right];
	nums[right] = tmp;
}

void quickSort(std::vector<std::string>& nums, int left, int right) {
	if (left >= right) return;
	int low = left, high = right;
	int i = low + 1;
	std::string pivot = nums[left];
	while (i <= high) {
		if ((nums[i] + pivot) > (pivot + nums[i])) {
			swap(nums, i, high);
			--high;
		} else if ((nums[i] + pivot) < (pivot + nums[i])) {
			swap(nums, i, low);
			++i;
			++low;
		} else {
			++i;
		}
	}
	quickSort(nums, left, low - 1);
	quickSort(nums, high + 1, right);
}

std::string PrintMinNumber(std::vector<int>& numbers) {
	std::vector<std::string> vec(numbers.size());
	for (int i = 0; i < numbers.size(); ++i) {
		vec[i] = std::to_string(numbers[i]);
	}
	quickSort(vec, 0, numbers.size() - 1);
	std::string res = "";
	for (int i = 0; i < vec.size(); ++i) {
		res += vec[i];
	}
	return res;
}

int main()
{
	std::vector<int> nums = {3, 32, 321};
	std::string res = PrintMinNumber(nums);
	std::cout << res << "\n";
}