// 题目：实现一个计算函数，该函数接受一个整数数组和一个回调函数作为参数。
// 回调函数用于对每个数组元素进行操作（比如，计算每个元素的平方），并将操作后的结果存储回原数组。
#include <iostream>
typedef int (*Fun)(int);

int doubleNum(int x) {
    return x * x;
}

void calFun(int arr[], int size, Fun callback) {
    for (int i = 0; i < size; ++i) {
        arr[i] = callback(arr[i]);
    }
}

int main() {
    Fun fun = doubleNum;
    int nums[] = {7, 6, 6, 4, 3, 2, 0};
    calFun(nums, 7, fun);
    for (const auto e: nums) {
        std::cout << e << " ";
    }

}