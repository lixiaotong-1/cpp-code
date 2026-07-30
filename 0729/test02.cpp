// 给你一棵二叉树的根节点，返回该树的 直径 。
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
// 两节点之间路径的 长度 由它们之间边数表示。
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

void createTree(std::vector<TreeNode*>& vec) {
	if (vec.size() == 0) {
		return;
	}
	std::queue<TreeNode*> q;
	q.push(vec[0]);
	int idx = 1;
	while (!q.empty() && idx < vec.size()) {
		TreeNode* top = q.front();
		q.pop();
		if (idx < vec.size()) {
			top->left = vec[idx];
			if (vec[idx] != nullptr) {
				q.push(vec[idx]);
			}
			++idx;
		}
		if (idx < vec.size()) {
			top->right = vec[idx];
			if (vec[idx] != nullptr) {
				q.push(vec[idx]);
			}
			++idx;
		}
	}
}

void delTreeNode(std::vector<TreeNode*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        delete vec[i];
    }
}

int maxdiameter = 0;

int calHight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = calHight(root->left);
    int right = calHight(root->right);
    maxdiameter = std::max(maxdiameter, left + right);
    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    calHight(root);
    return maxdiameter;
}

int main() {
	std::vector<TreeNode*> vec;
	std::string num;
	while (std::cin >> num) {
        if (num == "null") {
            vec.push_back(nullptr);
        } else {
            vec.push_back(new TreeNode(std::stoi(num)));
        }
	}
    if (vec.size() == 0) {
        return 0;
    }
	createTree(vec);
    int res = diameterOfBinaryTree(vec[0]);
    std::cout << res << "\n";
    delTreeNode(vec);
    return 0;
}