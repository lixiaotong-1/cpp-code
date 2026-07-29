// 翻转二叉树
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

void swap(TreeNode*& left, TreeNode*& right) {
    TreeNode* tmp = left;
    left = right;
    right = tmp;
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
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
    TreeNode* res = invertTree(vec[0]);
    printTree(res);
    delTreeNode(vec);
    return 0;
}