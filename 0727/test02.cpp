#include <iostream>
#include <vector>
#include <algorithm>
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

int getHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int left_height = getHeight(root->left);
	if (left_height == -1) {
		return -1;
	}
	int right_height = getHeight(root->right);
	if (right_height == -1) {
		return -1;
	}
	if (std::abs(left_height - right_height) > 1) {
		return -1;
	}
	return std::max(left_height, right_height) + 1;
}

bool isBalanced(TreeNode* root) {
	return getHeight(root) != -1;
}

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

int main()
{
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
    bool res = isBalanced(vec[0]);
    if (res) {
        std::cout << "是平衡二叉树" << "\n";
    } else {
        std::cout << "不是平衡二叉树" << "\n";
    }
    delTreeNode(vec);
    return 0;
}