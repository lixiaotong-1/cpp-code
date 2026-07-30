// 给你两棵二叉树： root1 和 root2 。
// 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
// 你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
// 否则，不为 null 的节点将直接作为新二叉树的节点。
// 返回合并后的二叉树。
// 注意: 合并过程必须从两个树的根节点开始。
// 给你一棵二叉树的根节点，返回该树的 直径 。
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
// 两节点之间路径的 长度 由它们之间边数表示。
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};

void createTree(std::vector<TreeNode*>& vec) {
	if (vec.size() == 0) {
		return;
	}
	std::queue<TreeNode*> q;
	q.push(vec[0]);
	int idx = 1;
	while (!q.empty() && idx < vec.size()) {
		TreeNode* top = q.front();
		q.pop();
		if (idx < vec.size()) {
			top->left = vec[idx];
			if (vec[idx] != nullptr) {
				q.push(vec[idx]);
			}
			++idx;
		}
		if (idx < vec.size()) {
			top->right = vec[idx];
			if (vec[idx] != nullptr) {
				q.push(vec[idx]);
			}
			++idx;
		}
	}
}

void delTreeNode(std::vector<TreeNode*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        delete vec[i];
        vec[i] = nullptr;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "null" << "\n";
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* top = q.front();
        if (top == nullptr) {
            std::cout << "null" << " ";
        } else {
            std::cout << top->val << " ";
        }
        q.pop();
        if (top->left) {
            q.push(top->left);
        }
        if (top->right) {
            q.push(top->right);
        }
    }
    std::cout << "\n";
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 != nullptr && root2 != nullptr) {
        root1->val += root2->val;
        TreeNode* left = mergeTrees(root1->left, root2->left);
        TreeNode* right =  mergeTrees(root1->right, root2->right);
        root1->left = left;
        root1->right = right;
        return root1;
    }
    if (root1 == nullptr && root2 != nullptr) {
        root1 = root2;
        return root1;
    }
    if (root2 == nullptr && root1 != nullptr) {
        return root1;
    }
    return nullptr;
}

int main() {
	std::vector<TreeNode*> vec1;
    std::vector<TreeNode*> vec2;
	std::string line1, line2;
	getline(std::cin, line1);
    getline(std::cin, line2);
    std::stringstream ss1(line1);
    std::stringstream ss2(line2);
    std::string substr;
    while (ss1 >> substr) {
        if (substr == "null") {
            vec1.push_back(nullptr);
        } else {
            vec1.push_back(new TreeNode(std::stoi(substr)));
        }
    }
    while (ss2 >> substr) {
        if (substr == "null") {
            vec2.push_back(nullptr);
        } else {
            vec2.push_back(new TreeNode(std::stoi(substr)));
        }
    }
	createTree(vec1);
    createTree(vec2);
    TreeNode* res = mergeTrees(vec1[0], vec2[0]);
    printTree(res);
    delTreeNode(vec1);
    delTreeNode(vec2);
    return 0;
}