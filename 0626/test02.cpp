// 请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，
// 需要实现的功能有：
// get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1
// add(value)：将价格为 value 的商品加入待结算商品队列的尾部
// remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1
// 注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1)
#include <iostream>
#include <queue>
#include <stack>

class Checkout {
public:
    std::deque<int> maxq;
	std::queue<int> dataq;
    Checkout() {}
    int get_max() {
        if (!maxq.empty()) {
			return maxq.front();
		} else {
			return -1;
		}
    }
    
    void add(int value) {
		dataq.push(value);
        while (!maxq.empty() && value > maxq.back()) {
			maxq.pop_back();
		}
		maxq.push_back(value);
    }
    
    int remove() {
		if (dataq.empty()) {
			return -1;
		}
		int val = dataq.front();
        if (val == maxq.front()) {
			maxq.pop_front();
		}
		dataq.pop();
		return val;
    }
};

int main() {
	// ["Checkout","add","add","get_max","remove","get_max"]
	// [[],[4],[7],[],[],[]]
	Checkout checkout;
	checkout.add(4);
	checkout.add(7);
	int max = checkout.get_max();
	std::cout << max << "\n";
	int re = checkout.remove();
    std::cout << re << "\n";
	max = checkout.get_max();
	std::cout << max << "\n";
	return 0;
}