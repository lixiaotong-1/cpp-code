// 给定一个二叉树 root ，返回其最大深度。
// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

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
        if (top == nullptr) {
            continue;
        }
        if (idx < vec.size()) {
            top->left = vec[idx];
            q.push(vec[idx]);
            idx++;
        }
        if (idx < vec.size()) {
            top->right = vec[idx];
            q.push(vec[idx]);
            idx++;
        }
    }
}

void delTreeNode(std::vector<TreeNode*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        delete vec[i];
    }
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
    int res = maxDepth(vec[0]);
    std::cout << "最深度为:" << res << "\n";
    delTreeNode(vec);
    return 0;
}