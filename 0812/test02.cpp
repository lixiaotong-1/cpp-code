// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。
// 你有多少种不同的方法可以爬到楼顶呢？
#include <iostream>
#include <vector>

int climbStairs(int n) {
	if (n <= 2) {
		return n;
	}
	int prev1 = 1, prev2 = 2;
	for (int i = 3; i <= n; ++i) {
		int cur = prev1 + prev2;
		prev1 = prev2;
		prev2 = cur;
	}
	return prev2;
	
}

int main() {
    int n = 10;
	int res = climbStairs(n);
	std::cout << res << "\n";
    return 0;
}