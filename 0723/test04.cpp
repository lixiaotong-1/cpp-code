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

int maxDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    TreeNode* node1 = new TreeNode(15, nullptr, nullptr);
    TreeNode* node2 = new TreeNode(7, nullptr,  nullptr);
    TreeNode* node3 = new TreeNode(20, node1, node2);
    TreeNode* node4 = new TreeNode(9, nullptr,  nullptr);
    TreeNode* root5 = new TreeNode(3, node4, node3);

    int res = maxDepth(root5);
    std::cout << res << "\n";
    return 0;
}