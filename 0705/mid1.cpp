// 前序遍历
#include <iostream>
#include <stack>
#include <vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

// 迭代
std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
	std::vector<int> res;
	if (root == nullptr) {
		return res;
	}
	TreeNode* cur = root;
	st.push(cur);
	while (!st.empty()) {
		while (cur != nullptr && cur->left) {
			st.push(cur->left);
			cur = cur->left;
		}
		TreeNode* tmp = st.top();
		st.pop();
		res.push_back(tmp->val);
		if (tmp->right) {
			cur = tmp->right;
			st.push(cur);
		}
	}
	return res;
}

int main()
{
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, node3, nullptr);
	TreeNode* node1 = new TreeNode(1, nullptr, node2);
    std::vector<int> res = inorderTraversal(node1);
	for (const auto e: res) {
		std::cout << e << " ";
	}
	std::cout << "\n";
    return 0;
}