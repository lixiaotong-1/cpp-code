// 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
// 实现 MyHashMap 类：
// MyHashMap() 用空映射初始化对象
// void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。
// 如果 key 已经存在于映射中，则更新其对应的值 value 。
// int get(int key) 返回特定的 key 所映射的 value ；
// 如果映射中不包含 key 的映射，返回 -1 。
// void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
// 最多调用 10000 次 put、get 和 remove 方法

#include <iostream>

class MyHashMap {
public:
    MyHashMap() {
        for (int i = 0; i < SIZE; ++i) {
			arr[i] = nullptr;
		}
    }
    
    void put(int key, int value) {
        int idx = hash(key);
		if (arr[idx] == nullptr) {
			Node* newnode = new Node(key, value);
			arr[idx] = newnode;
		} else {
			Node* p = arr[idx];
			while (p != nullptr) {
				if (p->key == key) {
					p->val = value;
					return;
				}
				p = p->next;
			}
			Node* newnode = new Node(key, value);
			newnode->next = arr[idx];
			arr[idx] = newnode;
		}
    }
    
    int get(int key) {
        int idx = hash(key);
		if (arr[idx] == nullptr) {
			return -1;
		} else {
			Node* p = arr[idx];
			int val = -1;
			while (p != nullptr) {
				if (p->key == key) {
					val = p->val;
					break;
				}
				p = p->next;
			}
			return val;
		}
    }
    
    void remove(int key) {
        int idx = hash(key);
		if (arr[idx] == nullptr) {
			return;
		} else {
			Node* p = arr[idx];
			Node* dummy = new Node(-1, -1);
			dummy->next = p;
			Node* q = dummy;
			while (p != nullptr) {
				if (p->key == key) {
					q->next = p->next;
					delete p;
					break;
				}
				p = p->next;
				q = q->next;
			}
			arr[idx] = dummy->next;
		}
    }
private:
	struct Node {
		int key;
		int val;
		struct Node* next;
		Node(int k, int v): key(k), val(v), next(nullptr) {}
	};
	static const int SIZE = 1009; // 非static成员属于对象，不能当作编译器常量
	Node* arr[SIZE];
	int hash(int a) {
		return a % SIZE;
	}
};

int main() {
	// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
	// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
	MyHashMap map;
	map.put(1, 1);
	map.put(2, 2);
	int v = map.get(1);
	std::cout << v << "\n";
	v = map.get(3);
	std::cout << v << "\n";
	map.put(2, 1);
	v = map.get(3);
	std::cout << v << "\n";
	map.remove(2);
	v = map.get(3);
	std::cout << v << "\n";
	return 0;
}