// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，
// 并支持普通栈的全部四种操作（push、top、pop 和 empty）。
// 实现 MyStack 类：
// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
#include <iostream>
#include <queue>

class MyStack {
public:
	std::queue<int> q1;
	std::queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
		int val = q1.back();
		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		while (!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}
        return val;
    }
    
    int top() {
        int val = q1.back();
		return val;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
	// ["MyStack", "push", "push", "top", "pop", "empty"]
	// [[], [1], [2], [], [], []]
	MyStack st;
	st.push(1);
	st.push(2);
	int res = st.top();
	std::cout << res << "\n";
	res = st.pop();
	std::cout << res << "\n";
	bool isempty = st.empty();
	std::cout << isempty << "\n";
	return 0;
}