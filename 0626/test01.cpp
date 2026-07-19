// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
// 计算按此排列的柱子，下雨之后能接多少雨水。
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int trap(std::vector<int>& height) {
	std::stack<int> st;
	int sz = height.size();
	int res = 0;
	for (int i = 0; i < sz; ++i) {
		if (st.empty() || height[st.top()] >= height[i]) {
			st.push(i);
		} else {
			while (!st.empty() && height[st.top()] < height[i]) {
				int val = height[st.top()];
				while (!st.empty() && height[st.top()] == val) {
					st.pop();
				}
				if (st.empty()) {
					st.push(i);
					break;
				}
				int diff = std::min(height[i] - val, height[st.top()] - val);
				int collect = diff * (i - st.top() - 1);
				res += collect;
			}
			st.push(i);
		}
	}
	return res;
}

int main() {
	std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int res = trap(height);
	std::cout << res << "\n";
	return 0;
}