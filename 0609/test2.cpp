// 编写一个程序，定义一个整型数组 arr，
// 包含 10 个元素，使用 memset 将数组的所有元素初始化为 0，并打印数组的内容以验证。
// 编写一个程序，定义两个整型数组 src 和 dest，
// 其中 src 包含 5 个元素 {1, 2, 3, 4, 5}，
// 使用 memcpy 将 src 数组的内容复制到 dest 数组中，并打印 dest 数组的内容。
#include <iostream>
using std::cout;

int main()
{
    int len = 10;
    int arr[len];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int src[5] = {1, 2, 3, 4, 5};
    int dest[10] = {};
    int data_len = 5;
    memcpy(dest, src, sizeof(int) * data_len);
    for (int i = 0; i < data_len; ++i) {
        cout << dest[i] << " ";
    }
    cout << "\n";
}