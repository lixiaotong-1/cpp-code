#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
	if (left == nullptr && right == nullptr) {
		return true;
	}
	if (left ==nullptr || right == nullptr) {
		return false;
	}
	return left->val == right->val && isMirror(left->left, right->right)
			&& isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	if (root == nullptr) {
		return true;
	}
	return isMirror(root->left, root->right);
}

int main() {
    TreeNode* node11 = new TreeNode(3, nullptr, nullptr);
    TreeNode* node22 = new TreeNode(3, nullptr,  nullptr);
    TreeNode* node1 = new TreeNode(2, nullptr, node11);
    TreeNode* node2 = new TreeNode(2, nullptr,  node22);
    TreeNode* root1 = new TreeNode(1, node1, node2);

    bool res = isSymmetric(root1);
    std::cout << res << "\n";
    return 0;
}