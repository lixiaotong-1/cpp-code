// 给你一个字符串 s，找到 s 中最长的 回文 子串。
#include <iostream>
#include <vector>
#include <climits>

// std::string longestPalindrome(std::string s) {
// 	int n = s.size();
// 	std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
// 	for (int i = 0; i < n; ++i) {
// 		dp[i][i] = true;
// 	}
// 	int max_len = 1;
// 	int start = 0;
// 	for (int len = 2; len <= n; ++len) {
// 		for (int i = 0; i < n + 1 - len; ++i) {
// 			int j = i + len - 1;
// 			if (s[i] == s[j]) {
// 				if (j - i <= 2) {
// 					dp[i][j] = true;
// 				} else {
// 					dp[i][j] = dp[i + 1][j - 1];
// 				}
// 				if (dp[i][j] && max_len < len) {
// 					max_len = len;
// 					start = i;
// 				}
// 			}
// 		} 
// 	}
// 	return s.substr(start, max_len);
// }

int isPalindrome(std::string s, int left, int right) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		--left;
		++right;
	}
	return right - left - 1;
}

// 中心扩散
std::string longestPalindrome(std::string s) {
	int n = s.size();
	if (n < 2) {
		return s;
	}

	int max_len = 1;
	int start = 0;
	for (int i = 0; i < n; ++i) {
		int len1 = isPalindrome(s, i, i);
		int len2 = isPalindrome(s, i, i + 1);
		int len = std::max(len1, len2);
		if (len > max_len) {
			max_len = len;
			start = i - (len - 1) / 2;
		}
	}
	return s.substr(start, max_len);
}


int main() {
    std::string str = "babad";
	std::string res = longestPalindrome(str);
	std::cout << res << "\n";
    return 0;
}