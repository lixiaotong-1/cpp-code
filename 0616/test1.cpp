// 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 s 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

std::string removeDuplicates(std::string s) {
	std::stack<char> st;
	for (int i = 0; i < s.size(); ++i) {
		if (!st.empty() && st.top() == s[i]) {
			st.pop();
		} else {
			st.push(s[i]);
		}
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
	std::string s = "abbaca";
	std::string res = removeDuplicates(s);
	std::cout << res << "\n";
}
