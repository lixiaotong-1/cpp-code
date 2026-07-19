// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* partition(ListNode* head, int x)
{
    ListNode* dummy1 = new ListNode(-1);
    ListNode* dummy2 = new ListNode(-1);
	ListNode* cur1 = dummy1, *cur2 = dummy2;
	ListNode* cur = head;
	while (cur != nullptr) {
		if (cur->val < x) {
			ListNode* newnode = new ListNode(cur->val);
			cur1->next = newnode;
			cur1 = cur1->next;
		} else if (cur->val >= x){
			ListNode* newnode = new ListNode(cur->val);
			cur2->next = newnode;
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
	if (cur1 != nullptr) {
		cur1->next = dummy2->next;
		return dummy1->next;
	} else {
		return dummy2->next;
	}
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
	ListNode second(4);
	ListNode third(3);
	ListNode fourth(2);
	ListNode fifth(5);
	ListNode sixth(2);
	list1.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	fifth.next = &sixth;

	ListNode* node = partition(&list1, 3);
	printList(node);
    return 0;
}