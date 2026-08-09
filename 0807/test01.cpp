// 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

#include <iostream>
#include <sstream>
#include <queue>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int v, Node* l, Node* r, Node* n): val(v), left(l), right(r), next(n) {}
  Node(int v): val(v), left(nullptr), right(nullptr), next(nullptr) {}
};


void createTree(std::vector<Node*>& vec) {
	if (vec.size() == 0) {
        return;
    }
    std::queue<Node*> q;
    q.push(vec[0]);
    int idx = 1;
    while (!q.empty() && idx < vec.size()) {
        Node* top = q.front();
        q.pop();
        if (top == nullptr) {
            continue;
        }
        if (idx < vec.size()) {
            top->left = vec[idx];
            q.push(vec[idx]);
            idx++;
        }
        if (idx < vec.size()) {
            top->right = vec[idx];
            q.push(vec[idx]);
            idx++;
        }
    }
}

void delTreeNode(std::vector<Node*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        delete vec[i];
    }
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    Node* cur = root;
    while (cur->next != nullptr) {
        std::cout << cur->next->val << " ";
        cur = cur->next;
    }
    std::cout << "#" << " ";
    printTree(root->left);
}

// 层序遍历
Node* connect(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    std::queue<Node*> q;
    q.push(root);
    root->next = nullptr;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            Node* top = q.front();
            q.pop();
            if (i != sz - 1) {
                top->next = q.front();
            }
            if (top->left != nullptr) {
                q.push(top->left);
            }
            if (top->right != nullptr) {
                q.push(top->right);
            }
        }
    }
    return root;
}

int main() {
    std::vector<Node*> vec1;
	std::string line1;
	getline(std::cin, line1);
    std::stringstream ss1(line1);
    std::string substr;
    while (ss1 >> substr) {
        if (substr == "null") {
            vec1.push_back(nullptr);
        } else {
            vec1.push_back(new Node(std::stoi(substr), nullptr, nullptr, nullptr));
        }
    }
	createTree(vec1);
    Node* res = connect(vec1[0]);
    printTree(res);
    std::cout << "\n";
    delTreeNode(vec1);
    return 0;
}