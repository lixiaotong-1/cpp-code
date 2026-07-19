// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
// 如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
// 则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
#include <iostream>
#include <vector>
#include <unordered_map>

class LRUCache {
    struct Node;
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        capacity = 0;
        size = 0;
        map.clear();
    }

    void removeCurNode(Node* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void moveNodeToHead(Node* cur) {
        cur->next = head->next;
        head->next = cur;
        cur->next->prev = cur;
        cur->prev = head;
    }
 	
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* cur = map[key];
        int res = cur->value;
        removeCurNode(cur);
        moveNodeToHead(cur);
        return res;
    }

    void deleteLastNode(Node* lastnode) {
        lastnode->prev->next = tail;
        tail->prev = lastnode->prev;
        delete lastnode;
        lastnode = nullptr;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* cur = map[key];
            cur->value = value;
            removeCurNode(cur);
            moveNodeToHead(cur);
        } else {
            Node* newnode = new Node(key, value);
            if (size >= capacity) {
                Node* lastnode = tail->prev;
                map.erase(lastnode->key);
                deleteLastNode(lastnode);
                map[key] = newnode;
                moveNodeToHead(newnode);
            } else {
                map[key] = newnode;
                moveNodeToHead(newnode);
                ++size;
            }
        }
    }

private:
	typedef struct Node {
		int key;
		int value;
		Node* next;
		Node* prev;
        Node(): key(0), value(0), next(nullptr), prev(nullptr) {}
		Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
	} Node;
	Node* head;
	Node* tail;
	std::unordered_map<int, Node*> map;
	int capacity;
    int size;
};

int main() {
    LRUCache cache(2);
    // ["LRUCache","put","put","get","put","get","put","get","get","get"]
    // [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    // output : [null, null, null, 1, null, -1, null, -1, 3, 4]
    cache.put(1, 1);
    cache.put(2, 2);
    int res = cache.get(1);
    std::cout << res << "\n";
    cache.put(3, 3);
    res = cache.get(2);
    cache.put(4, 4);
    res = cache.get(1);
    std::cout << res << "\n";
    res = cache.get(3);
    std::cout << res << "\n";
    res = cache.get(4);
    std::cout << res << "\n";
    return 0;
}