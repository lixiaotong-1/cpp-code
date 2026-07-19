// 某教练同时带教两位学员，分别以链表 l1、l2 记录了两套核心肌群训练计划，
// 节点值为训练项目编号。两套计划仅有前半部分热身项目不同，后续正式训练项目相同。
// 请设计一个程序找出并返回第一个正式训练项目编号。
// 如果两个链表不存在相交节点，返回 null 。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lenmin = 0;
	int lenmax = 0;
	ListNode* curmin = headA, *curmax = headB;
	ListNode* dummy1 = new ListNode(-1);
	ListNode* dummy2 = new ListNode(-1);
	dummy1->next = headA;
	dummy2->next = headB;
	while (curmin != nullptr) {
		++lenmin;
		curmin = curmin->next;
	}
	while (curmax != nullptr) {
		++lenmax;
		curmax = curmax->next;
	}
	curmin = headA;
    curmax = headB;
	if (lenmin > lenmax) {
		int lentmp = lenmin;
		curmin = headB;
		curmax = headA;
		lenmin = lenmax;
		lenmax = lentmp;
	}
	int difflen = lenmax - lenmin;
	
	while (difflen) {
		curmax = curmax->next;
		--difflen;
	}
	while (curmin != nullptr && curmax != nullptr) {
		if (curmin == curmax) {
			return curmin;
		}
		curmin = curmin->next;
		curmax = curmax->next;
	}
	return nullptr;
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
	ListNode second(3);
	ListNode third(5);
	ListNode fourth(8);
	ListNode fifth(9);
	list1.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	
	ListNode list2(2);
	ListNode second2(4);
	ListNode third2(6);
	list2.next = &second2;
	second2.next = &third2;
	third2.next = &fourth;
	fourth.next = &fifth;

	ListNode* node = getIntersectionNode(&list1, &list2);
	printList(node);
    return 0;
}