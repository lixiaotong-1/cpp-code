// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
// 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* reverseList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* pre = nullptr, *cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* cur = &dummy;
    // 找到反转链表头节点的前一个节点
    int i = 0;
    for (; i < left - 1; ++i) {
        cur = cur->next;
    }
    ListNode* leftNode = cur;
    for (; i < right; ++i) {
        cur = cur->next;
    }
    //找到反转链表尾节点的后一个节点
    ListNode* rightNode = cur->next;
    cur->next = nullptr;
    ListNode* newhead = leftNode->next;
    leftNode->next = nullptr;
    leftNode->next = reverseList(newhead);
    newhead->next = rightNode;
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
    ListNode head(1);
	ListNode second(2);
	// ListNode third(3);
	// ListNode fourth(4);
    // ListNode fifth(5);
	head.next = &second;
	// second.next = &third;
	// third.next = &fourth;
    // fourth.next = &fifth;
	ListNode* node = reverseBetween(&head, 1, 2);
	printList(node);
    return 0;
}