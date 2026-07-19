// 给你一个以字符串表示的非负整数 num 和一个整数 k ，
// 移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

std::string removeKdigits(std::string num, int k) {
	if (k == num.size()) {
		return "0";
	}
	std::stack<char> st;
	for (const char c: num) {
		while (!st.empty() && k > 0 && st.top() > c) {
			st.pop();
			--k;
		}
		if (st.empty() && c == '0') {
			continue;
		}
		st.push(c);
	}
	while (!st.empty() && k > 0) {
		st.pop();
		--k;
	}
	if (st.empty()) {
		return "0";
	}
	std::string res = "";
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	std::string s = "10";
	int k = 1;
	std::string res = removeKdigits(s, k);
	std::cout << res << "\n";
}
