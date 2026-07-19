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

void postorder(TreeNode* root, std::vector<int>& res) {
	if (root == nullptr) return;
	postorder(root->left, res);
	postorder(root->right, res);
	res.push_back(root->val);
}

// 递归
std::vector<int> postorderTraversal(TreeNode* root) {
	std::vector<int> res; 
	postorder(root, res);
	return res;
}


int main()
{
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, node3, nullptr);
	TreeNode* node1 = new TreeNode(1, nullptr, node2);
    std::vector<int> res = postorderTraversal(node1);
	for (const auto e: res) {
		std::cout << e << " ";
	}
	std::cout << "\n";
    return 0;
}