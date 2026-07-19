// 编写一个程序，定义两个整型数组 src 和 dest，
// 其中 src 包含 5 个元素 {1, 2, 3, 4, 5}，
// 使用 memcpy 将 src 数组的内容复制到 dest 数组中，并打印 dest 数组的内容。
#include <iostream>
using std::cout;

int main()
{
    int src[5] = {1, 2, 3, 4, 5};
    int dest[6] = {};
    int len = 5;
    memcpy(dest, src, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        cout << dest[i] << " ";
    }
    cout << "\n";
}