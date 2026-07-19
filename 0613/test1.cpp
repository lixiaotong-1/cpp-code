// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
// 如果是，返回 true ；否则，返回 false 。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

// 偶数返回第一个中间节点
ListNode* middleNode(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* fast = head, *slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

ListNode* reverseList(ListNode* head)
{
	ListNode* cur = head, *pre = nullptr;
	while (cur != nullptr) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
        cur = next;
	}
	return pre;
}

bool isPalindrome(ListNode* head)
{
	ListNode* middle = middleNode(head);
	ListNode* newhead = reverseList(middle->next);
	ListNode* first = head, *second = newhead;
    bool res = true;
	while (first != nullptr && second != nullptr) {
		if (first->val != second->val) {
            res = false;
			break;
		}
		first = first->next;
		second = second->next;
	}
    // 还原链表
    middle->next = reverseList(newhead);

    return res;
}

int main()
{
    ListNode head(1);
	ListNode second(2);
	head.next = &second;
	bool istrue = isPalindrome(&head);
	std::cout << istrue << "\n";
    return 0;
}