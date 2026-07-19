
// 题目2：编写一个C语言程序，定义一个指针函数int* findMax(int arr[], int size)，该函数遍历一个整数数组，返回指向数组中最大值的指针。
// 在主函数中定义一个整数数组，调用findMax函数，并通过返回的指针打印数组中的最大值。
#include <iostream>

int* findMax(int arr[], int size) {
    int maxIdx = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return &arr[maxIdx];
}

int main() {
    int arr[5] = {4, 3, 7, 8, 10};
    int* maxPos = findMax(arr, 5);
    std::cout << *maxPos << "\n";
}
