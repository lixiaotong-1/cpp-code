// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。
// 返回 已排序的链表 。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* last = head, *pre = dummy;
	ListNode* cur = head->next;
	while (cur != nullptr) {
		if (cur->val != last->val) {
			cur = cur->next;
			last = last->next;
			pre = pre->next;
			continue;
		}
		while (cur != nullptr && cur->val == last->val) {
			cur = cur->next;
		}
		pre->next = cur;
		last = cur;
		if (cur == nullptr) {
			break;
		}
		cur = cur->next;
	}
	return dummy->next;
}

void printList(ListNode* head)
{
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

int main()
{
	ListNode list1(1);
	ListNode second(2);
	ListNode third(3);
	ListNode fourth(3);
	ListNode fifth(4);
	ListNode sixth(4);
	ListNode seventh(5);
	list1.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	fifth.next = &sixth;
	sixth.next = &seventh;

	ListNode* node = deleteDuplicates(&list1);
	printList(node);
    return 0;
}