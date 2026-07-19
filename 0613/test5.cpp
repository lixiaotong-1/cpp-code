// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

// ListNode* swapPairsRec(ListNode* head)
// {
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }
//     ListNode* newhead = swapPairs(head->next->next);
//     ListNode* pre = head, *cur = head->next;
//     cur->next = pre;
//     pre->next = newhead;
//     return cur;
// }

ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* cur = head, *pre = &dummy, *next = cur->next;
    while (next != nullptr) {
        pre->next = next;
        cur->next = next->next;
        next->next = cur;
        pre = cur;
        // 如果子链表只有一个节点不用继续交换了
        if (cur->next == nullptr) {
            break;
        }
        cur = cur->next;
        next = cur->next;
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
    ListNode head(1);
	ListNode second(2);
	ListNode third(3);
	ListNode fourth(4);
    // ListNode fifth(5);
	head.next = &second;
	second.next = &third;
	third.next = &fourth;
    // fourth.next = &fifth;
	ListNode* node = swapPairs(&head);
	printList(node);
    return 0;
}