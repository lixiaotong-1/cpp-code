// 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
// 完全二叉树 的定义如下：在完全二叉树中，
// 除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。
// 若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。

#include <iostream>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

int getHight(TreeNode* root) {
	int h = 0;
	if (root == nullptr) {
		return 0;
	}
	while (root) {
		++h;
		root = root->left;
	}
	return h;
}

// 如果左子树和右子树的高度相等，则左子树一定是满二叉树
// 如果左子树和右子树的高度不相等，则右子树一定是满二叉树
int countNodes(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int heightLeft = getHight(root->left);
	int heightRight = getHight(root->right);
	if (heightLeft == heightRight) {
		return (1 << heightLeft) + countNodes(root->right);
	} else {
		return (1 << heightRight) + countNodes(root->left);
	}
}



int main()
{
	TreeNode* node4 = new TreeNode(4, nullptr, nullptr);
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node1 = new TreeNode(1, node2, node3);
    int res = countNodes(node1);
	std::cout << res << "\n";
	
    return 0;
}