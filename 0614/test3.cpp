// 给定两个用链表表示的整数，每个节点包含一个数位。
// 这些数位是反向存放的，也就是个位排在链表首部。
// 编写函数对这两个整数求和，并用链表形式返回结果。

#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* cur1 = l1, *cur2 = l2;
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    int res = 0;
    while (cur1 != nullptr || cur2 != nullptr) {
        int val1 = cur1 == nullptr ? 0 : cur1->val;
        int val2 = cur2 == nullptr ? 0 : cur2->val;
        int tmpsum = val1 + val2 + res;
        ListNode* tmp = new ListNode(tmpsum % 10);
        if (tmpsum < 10) {
            res = 0;
        } else if (tmpsum >= 10) {
            res = tmpsum / 10;
        }
        cur->next = tmp;
        cur = cur->next;
        if (cur1 != nullptr) {
            cur1 = cur1->next;
        }
        if (cur2 != nullptr) {
            cur2 = cur2->next;
        }
    }
    if (res != 0) {
        ListNode* tmp = new ListNode(res);
        cur->next = tmp;
        cur = cur->next;
    }
    return dummy.next;
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
    ListNode list1(7);
	ListNode second(1);
	ListNode third(6);
	list1.next = &second;
	second.next = &third;

    ListNode list2(5);
	ListNode second2(9);
	ListNode third2(2);
	list2.next = &second2;
	second2.next = &third2;

	ListNode* node = addTwoNumbers(&list1, &list2);
	printList(node);
    return 0;
}

