// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* cur = dummy;
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->val < cur2->val) {
            cur->next = cur1;
            cur1 = cur1->next;
        } else {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    if (cur1 != nullptr) {
        cur->next = cur1;
    }
    if (cur2 != nullptr) {
        cur->next = cur2;
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
	ListNode third(4);
	list1.next = &second;
	second.next = &third;

    ListNode list2(1);
	ListNode second2(3);
	ListNode third2(4);
	list2.next = &second2;
	second2.next = &third2;

	ListNode* node = mergeTwoLists(&list1, &list2);
	printList(node);
    return 0;
}