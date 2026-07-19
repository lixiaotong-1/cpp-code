// 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，
// 请查找并返回倒数第 cnt 个训练项目编号对应的节点。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

// fast指针先走k步
ListNode* trainingPlan(ListNode* head, int cnt)
{
    if (head == nullptr) {
        return head;
    }
    ListNode* fast = head, *slow = head;
    for (int i = 0; i < cnt; ++i) {
        fast = fast->next;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    ListNode head(2);
	ListNode second(4);
	ListNode third(7);
	ListNode fourth(8);
	head.next = &second;
	second.next = &third;
	third.next = &fourth;
	ListNode* node = trainingPlan(&head, 1);
	std::cout << node->val << "\n";
	
    return 0;
}