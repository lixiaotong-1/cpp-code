// 请你仅使用两个栈实现先入先出队列。
// 队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
#include <iostream>
#include <stack>

class MyQueue {
public:
	std::stack<int> st1;
	std::stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
		st1.push(x);
    }
    
    int pop() {
        if (!st2.empty()) {
			int val = st2.top();
			st2.pop();
			return val;
		}
		while (!st1.empty()) {
			int val = st1.top();
			st2.push(val);
			st1.pop();
		}
		int val = st2.top();
		st2.pop();
		return val;
    }
    
    int peek() {
        if (!st2.empty()) {
			int val = st2.top();
			return val;
		}
		while (!st1.empty()) {
			int val = st1.top();
			st2.push(val);
			st1.pop();
		}
		int val = st2.top();
		return val;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
	// ["MyQueue", "push", "push", "peek", "pop", "empty"]
	// [[], [1], [2], [], [], []]
	MyQueue mq;
	mq.push(1);
	mq.push(2);
	int max = mq.peek();
	std::cout << max << "\n";
	int re = mq.pop();
    std::cout << re << "\n";
	bool isempty = mq.empty();
	std::cout << isempty << "\n";
	return 0;
}