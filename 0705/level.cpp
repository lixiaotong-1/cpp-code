// 层序遍历
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

// 层序迭代
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
	std::vector<std::vector<int>> res;
	std::queue<TreeNode*> que;
	if (root == nullptr) return res;
	que.push(root);
	int levelcnt = 1;
	while (!que.empty()) {
		std::vector<int> vec;
		int cnt = 0;
		while (cnt < levelcnt) {
			TreeNode* head = que.front();
			vec.push_back(head->val);
			que.pop();
			cnt++;
			if (head->left) {
				que.push(head->left);
			}
			if (head->right) {
				que.push(head->right);
			}
		}
		res.push_back(vec);
		levelcnt = que.size();
	}
	return res;
}


int main()
{
	TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
	TreeNode* node2 = new TreeNode(2, node3, nullptr);
	TreeNode* node1 = new TreeNode(1, nullptr, node2);
    std::vector<std::vector<int>> res = levelOrder(node1);
	for (const auto& item: res) {
		for (const auto e: item) {
			std::cout << e << " ";
		}
		std::cout << "\n";
	}
	
    return 0;
}