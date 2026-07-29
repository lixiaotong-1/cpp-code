// 给一个二叉树的根节点，返回所有左叶子之和
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

int sumOfLeftLeaves(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
    int leftsum = 0, rightsum = 0;
    if (root->left != nullptr) {
        if (root->left->left == nullptr && root->left->right == nullptr) {
            leftsum = root->left->val;
        } else {
            leftsum = sumOfLeftLeaves(root->left);
        }
    }
    if (root->right != nullptr) {
        rightsum = sumOfLeftLeaves(root->right);
    }
    return leftsum + rightsum;
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
    int res = sumOfLeftLeaves(vec[0]);
    std::cout << "左叶子之和为:" << res << "\n";
    delTreeNode(vec);
    return 0;
}