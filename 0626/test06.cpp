// 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
// 实现 MyHashSet 类：
// void add(key) 向哈希集合中插入值 key 。
// bool contains(key) 返回哈希集合中是否存在这个值 key 。
// void remove(key) 将给定值 key 从哈希集合中删除。
// 如果哈希集合中没有这个值，什么也不做。
#include <iostream>
class MyHashSet {
public:
    MyHashSet() {
        for (int i = 0; i < SIZE; ++i) {
			arr[i] = nullptr;
		}
    }
    
    void add(int key) {
        int idx = hash(key);
		Node* newnode = new Node(key);
		if (arr[idx] == nullptr) {
			arr[idx] = newnode;
		} else {
            Node* p = arr[idx];
            while (p) {
                if (p->key == key) {
                    return;
                }
                p = p->next;
            }
			newnode->next = arr[idx];
			arr[idx] = newnode;
		}
    }
    
    void remove(int key) {
        int idx = hash(key);
		Node* dummy = new Node(-1);
		dummy->next = arr[idx];
		Node* pre = dummy, *cur = arr[idx];
		if (cur == nullptr) {
			return;
		} else {
			while (cur) {
				if (cur->key == key) {
					pre->next = cur->next;
					delete cur;
                    arr[idx] = dummy->next;
					return;
				}
				cur = cur->next;
				pre = pre->next;
			}
		}
    }
    
    bool contains(int key) {
        int idx = hash(key);
		if (arr[idx] == nullptr) {
			return false;
		} else {
			Node* p = arr[idx];
			while (p) {
				if (p->key == key) {
					return true;
				}
				p = p->next;
			}
			return false;
		}
    }
private:
	struct Node {
		int key;
		struct Node* next;
		Node(int k): key(k), next(nullptr) {}
	};
	static const int SIZE = 1009;
	Node* arr[SIZE];
	int hash(int key) {
		return key % SIZE;
	}
};

int main() {
	// ["MyHashSet","add","add","add","remove","contains",
	// "add","add","add","remove","contains","add","add","add",
	// "remove","contains","add","add","add","remove","contains"]
	// [[],[1],[10001],[1],[1],[1],[7],[10007],[7],[7],
	// [7],[123],[10123],[123],[123],[123],[5000],[15000],
	// [5000],[5000],[5000]]
	MyHashSet set;
	set.add(1);
	set.add(10001);
    set.add(1);
    set.remove(1);
    bool isexist = set.contains(1);
    std::cout << isexist << "\n";

    set.add(7);
	set.add(10007);
    set.add(7);
    set.remove(7);
    isexist = set.contains(7);
    std::cout << isexist << "\n";

    set.add(123);
	set.add(10123);
    set.add(123);
    set.remove(123);
    isexist = set.contains(123);
    std::cout << isexist << "\n";

    set.add(5000);
	set.add(15000);
    set.add(5000);
    set.remove(5000);
    isexist = set.contains(5000);
    std::cout << isexist << "\n";

	return 0;
}