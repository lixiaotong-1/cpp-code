#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
	if (left == nullptr && right == nullptr) {
		return true;
	}
	if (left == nullptr || right == nullptr) {
		return false;
	}
	if (left->val != right->val) {
		return false;
	}
	return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	if (root == nullptr) {
		return true;
	}
	return isMirror(root->left, root->right);
}

int main()
{
	TreeNode* node2 = new TreeNode(2, nullptr, nullptr);
	TreeNode* node22 = new TreeNode(2, nullptr, nullptr);
	TreeNode* node1 = new TreeNode(1, node2, node22);
    int res = isSymmetric(node1);
	std::cout << res << "\n";
}