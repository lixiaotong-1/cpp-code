// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
// 同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
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

int max_sum = INT_MIN;

int gain(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_gain = std::max(0, gain(root->left));
    int right_gain = std::max(0, gain(root->right));
    max_sum = std::max(max_sum, left_gain + right_gain + root->val);
    return root->val + std::max(0, std::max(left_gain, right_gain));
}

int maxPathSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    gain(root);
    return max_sum;
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
	createTree(vec1);
    int res = maxPathSum(vec1[0]);
    std::cout << res << "\n";
    delTreeNode(vec1);
    return 0;
}