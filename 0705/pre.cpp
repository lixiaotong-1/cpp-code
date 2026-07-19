// 前序遍历
#include <iostream>
#include <vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

void preorder(TreeNode* root, std::vector<int>& res) {
	if (root == nullptr) return;
	res.push_back(root->val);
	preorder(root->left, res);
	preorder(root->right, res);
}

// 递归
std::vector<int> preorderTraversal(TreeNode* root) {
	std::vector<int> res; 
	preorder(root, res);
	return res;
}

int main()
{
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, node3, nullptr);
	TreeNode* node1 = new TreeNode(1, nullptr, node2);
    std::vector<int> res = preorderTraversal(node1);
	for (const auto e: res) {
		std::cout << e << " ";
	}
	std::cout << "\n";
    return 0;
}