// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。
// 与实际答案相差 10-5 以内的答案可以被接受。

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q != nullptr) {
		return false;
	}
	if (p != nullptr && q == nullptr) {
		return false;
	}
	if (p == nullptr && q == nullptr) {
		return true;
	}
	if (p->val != q->val) {
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, nullptr, nullptr);
	TreeNode* node1 = new TreeNode(1, node2, node3);
	
	TreeNode* node33 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node22 = new TreeNode(2, nullptr, nullptr);
	TreeNode* node11 = new TreeNode(1, node22, node33);
    bool res = isSameTree(node1, node11);
	std::cout << res << "\n";
	
    return 0;
}