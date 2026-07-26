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

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) {
		return true;
	}
	if (p == nullptr || q ==nullptr) {
		return false;
	}
	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* node1 = new TreeNode(2, nullptr, nullptr);
    TreeNode* node2 = new TreeNode(3, nullptr,  nullptr);
    TreeNode* root1 = new TreeNode(1, node1, node2);

    TreeNode* node11 = new TreeNode(2, nullptr, nullptr);
    TreeNode* node22 = new TreeNode(3, nullptr,  nullptr);
    TreeNode* root11 = new TreeNode(1, node11, node22);
    bool res = isSameTree(root11, root1);
    std::cout << res << "\n";
    return 0;
}