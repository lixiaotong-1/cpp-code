// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
// 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
// 如果存在，返回 true ；否则，返回 false 。
// 叶子节点 是指没有子节点的节点。
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
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
        vec[i] = nullptr;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "null" << "\n";
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* top = q.front();
        if (top == nullptr) {
            std::cout << "null" << " ";
        } else {
            std::cout << top->val << " ";
        }
        q.pop();
        if (top->left) {
            q.push(top->left);
        }
        if (top->right) {
            q.push(top->right);
        }
    }
    std::cout << "\n";
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }
    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);
    return left || right;
}

int main() {
	std::vector<TreeNode*> vec1;
	std::string line1;
	getline(std::cin, line1);
    std::stringstream ss1(line1);
    std::string substr;
    while (ss1 >> substr) {
        if (substr == "null") {
            vec1.push_back(nullptr);
        } else {
            vec1.push_back(new TreeNode(std::stoi(substr)));
        }
    }
    int targetSum = 0;
    std::cin >> targetSum;
	createTree(vec1);
    bool res = hasPathSum(vec1[0], targetSum);
    std::cout << res << "\n";
    delTreeNode(vec1);
    return 0;
}