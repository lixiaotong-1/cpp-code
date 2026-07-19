// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
	int sz = temperatures.size();
	std::vector<int> res(sz, 0);
	std::stack<int> st;
	for (int i = 0; i < sz; ++i) {
		while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
			int topIdx = st.top();
			res[topIdx] = i - topIdx;
			st.pop();
		}
		st.push(i);
	}
	return res;
}

int main() {
	std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	std::vector<int> res = dailyTemperatures(temperatures);
	for (const auto e: res) {
		std::cout << e << " ";
	}
	std::cout << "\n";
    return 0;
}