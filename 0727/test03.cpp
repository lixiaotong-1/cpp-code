#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
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

int getHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
    int left = getHeight(root->left);
    int right = getHeight(root->right);
	if (root->left == nullptr) {
		return right + 1;
	}
	if (root->right == nullptr) {
		return left + 1;
	}
	return std::min(left, right) + 1;
}

int minDepth(TreeNode* root) {
	return getHeight(root); 
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
    int res = minDepth(vec[0]);
    std::cout << "最小深度为:" << res << "\n";
    delTreeNode(vec);
    return 0;
}