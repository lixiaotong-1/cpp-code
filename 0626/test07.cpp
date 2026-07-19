// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
#include <iostream>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
	int left = 0, right = 0;
	int sz = s.size();
	std::unordered_set<char> set;
	int ret = 0;
	while (right < sz) {
		char toinsert = s[right];
		if (set.find(toinsert) == set.end()) {
			set.insert(toinsert);
		} else {
			int len = right - left;
			if (len > ret) ret = len;
			while (set.find(toinsert) != set.end()) {
				set.erase(s[left]);
				++left;
			}
			set.insert(toinsert);
		}
		++right;
	}
	int len = right - left;
	if (len > ret) ret = len;
	return ret;
}
int main() {
	std::string s = "abcabcbb";
	int res = lengthOfLongestSubstring(s);
	std::cout << res << "\n";
	return 0;
}