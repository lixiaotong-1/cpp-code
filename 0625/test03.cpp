// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// MinStack() 初始化堆栈对象。
// void push(int value) 将元素 value 推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。
#include <iostream>
#include <stack>

class MinStack {
public:
	std::stack<int> dataStack;
	std::stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        dataStack.push(value);
		if (minStack.empty()) {
			minStack.push(value);
		} else {
			if (value <= minStack.top()) {
				minStack.push(value);
			}
		}
    }
    
    void pop() {
        if (dataStack.top() == minStack.top()) {
			dataStack.pop();
			minStack.pop();
		} else {
			dataStack.pop();
		}
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main()
{
// ["MinStack","push","push","push","getMin","pop","getMin","pop","getMin","pop","push","push","push","getMin","pop","top","getMin","pop","getMin","pop"]
// [[],[0],[1],[0],[],[],[],[],[],[],[-2],[-1],[-2],[],[],[],[],[],[],[]]
	MinStack minStack;
	minStack.push(0);
	minStack.push(1);
	minStack.push(0);
	std::cout << minStack.getMin() << "\n";
	minStack.pop();
	std::cout << minStack.getMin() << "\n";
	minStack.pop();
    std::cout << minStack.getMin() << "\n";
	minStack.pop();
    minStack.push(-2);
	minStack.push(-1);
	minStack.push(-2);
    std::cout << minStack.getMin() << "\n";
    minStack.pop();
    minStack.top();
	std::cout << minStack.getMin() << "\n";
    minStack.pop();
    std::cout << minStack.getMin() << "\n";
    minStack.pop();
    return 0;
}