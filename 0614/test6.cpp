// 对链表进行插入排序
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* insertionSortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* toinsert = head->next;
    ListNode* cur = dummy->next;
    while (toinsert != nullptr) {
        if (toinsert->val >= cur->val) {
            toinsert = toinsert->next;
            cur = cur->next;
            continue;
        }
        ListNode* start = dummy->next, *pre = dummy;
        while (toinsert->val >= start->val) {
            start = start->next;
            pre = pre->next;
        }
        cur->next = toinsert->next;
        toinsert->next = start;
        pre->next = toinsert;
        toinsert = cur->next;
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
	ListNode list1(4);
	ListNode second(2);
	ListNode third(1);
	ListNode fourth(3);
	list1.next = &second;
	second.next = &third;
	third.next = &fourth;

	ListNode* node = insertionSortList(&list1);
	printList(node);
    return 0;
}