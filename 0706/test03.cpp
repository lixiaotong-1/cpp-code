// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。
// 与实际答案相差 10-5 以内的答案可以被接受。

#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftSum = 0;
	if (root->left) {
		if (root->left->left == nullptr && root->left->right == nullptr) {
			leftSum = root->left->val;
		} else {
			leftSum = sumOfLeftLeaves(root->left);
		}
	}
	int rightSum = 0;
	if (root->right) {
		rightSum = sumOfLeftLeaves(root->right);
	}
	return leftSum + rightSum;
}

int main()
{
	TreeNode* node9 = new TreeNode(9, nullptr, nullptr);
	TreeNode* node15 = new TreeNode(15, nullptr, nullptr);
	TreeNode* node7 = new TreeNode(7, nullptr, nullptr);
	TreeNode* node20 = new TreeNode(20, node15, node7);
	TreeNode* node3 = new TreeNode(3, node9, node20);
    int res = sumOfLeftLeaves(node3);
	std::cout << res << "\n";
	
    return 0;
}