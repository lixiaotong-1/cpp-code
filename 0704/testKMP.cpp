// kmp算法实现

#include <iostream>
#include <vector>
#include <string>

// next[i]表示0～i的子串，最长的公共前后缀长度。
std::vector<int> getNext(const std::string& pattern) {
    std::vector<int> next(pattern.size(), 0);
    int size = pattern.size();
    next[0] = 0;
    int i = 1, j = 0;
    for (i = 1; i < size; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

// KMP算法，在text中查找第一次出现pattern的下标
int KMP(const std::string& text, const std::string& pattern) {
    int patternLen = pattern.size();
    int textLen = text.size();
    if (textLen == 0) {
        return -1;
    }
    if (patternLen == 0) {
        return 0;
    }
    std::vector<int> next = getNext(pattern);
    int j = 0;
    for (int i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
            if (patternLen - j > textLen - i) {
                return -1;
            }
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == patternLen) {
            return i - patternLen + 1;
        }
    }
    return -1;
}

int main() {
    std::string text("aabaabaaf");
    std::string pattern("aabaaf");
    int idx = KMP(text, pattern);
    std::cout << idx << "\n";
}
