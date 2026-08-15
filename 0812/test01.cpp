// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
#include <iostream>
#include <vector>

int fib(int n) {
	if (n <= 1) {
		return n;
	}
    int prev1 = 0, prev2 = 1;
	for (int i = 2; i < n + 1; ++i) {
		int cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
	}
	return prev2;
}

int main() {
    int res = fib(2);
	std::cout << res << "\n";
	res = fib(3);
	std::cout << res << "\n";
	res = fib(4);
	std::cout << res << "\n";
    return 0;
}