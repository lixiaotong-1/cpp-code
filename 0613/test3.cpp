// 给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别分组，
//保持它们原有的相对顺序，然后把偶数索引节点分组连接到奇数索引节点分组之后，返回重新排序的链表。
//第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
//请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
//你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode* oddEvenList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* newhead = head->next;
    while (odd->next != nullptr && odd->next->next != nullptr) {
        ListNode* nextodd = even->next;
        ListNode* nexteven = even->next->next;
        odd->next = nextodd;
        even->next = nexteven;
        odd = nextodd;
        even = nexteven;
    }
    odd->next = newhead;
    return head;
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
	ListNode third(3);
	ListNode fourth(4);
    ListNode fifth(5);
	head.next = &second;
	second.next = &third;
	third.next = &fourth;
    fourth.next = &fifth;
	ListNode* node = oddEvenList(&head);
	printList(&head);
    return 0;
}