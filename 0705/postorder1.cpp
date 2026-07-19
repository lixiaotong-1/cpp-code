// 后序遍历
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
std::vector<int> postorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    std::vector<int> res;
    if (root == nullptr) return res;
    TreeNode* pre = nullptr;
    st.push(root);
    TreeNode* cur = root;
    while (!st.empty()) {
        while (cur != nullptr && cur->left != nullptr) {
            st.push(cur->left);
            cur = cur->left;
        }
        TreeNode* tmp = st.top();
        if (tmp->right == pre || tmp->right == nullptr) {
            st.pop();
            res.push_back(tmp->val);
            pre = tmp;
            cur = nullptr;
        } else {
            cur = tmp->right;
            if (cur != nullptr) {
                st.push(cur);
            }
        }
    }
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