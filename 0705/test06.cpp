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

std::vector<double> averageOfLevels(TreeNode* root) {
	std::vector<double> res;
	if (root == nullptr) return res;
	std::queue<TreeNode*> que;
	que.push(root);
	int cntLevel = 1;
	while (!que.empty()) {
		double sum = 0;
		int cnt = 0;
		while (cnt < cntLevel) {
			TreeNode* tmp = que.front();
			que.pop();
			++cnt;
			sum += tmp->val;
			if (tmp->left) {
				que.push(tmp->left);
			}
			if (tmp->right) {
				que.push(tmp->right);
			}
		}
		res.push_back(sum / cntLevel);
		cntLevel = que.size();
	}
	return res;
}

int main()
{
	TreeNode* node5 = new TreeNode(7, nullptr, nullptr);
    TreeNode* node4 = new TreeNode(15, nullptr, nullptr);
    TreeNode* node3 = new TreeNode(20, node4, node5);
	TreeNode* node2 = new TreeNode(9, nullptr, nullptr);
	TreeNode* node1 = new TreeNode(3, node2, node3);
    std::vector<double> res = averageOfLevels(node1);
	for (const auto e: res) {
        std::cout << e << " ";
    }
    std::cout << "\n";
	
    return 0;
}