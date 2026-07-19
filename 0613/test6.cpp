// 给你一个链表的头节点 head ，判断链表中是否有环。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
// 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

// 使用快慢指针，快指针每次多走一步，那么若干次之后会比慢指针多走一圈达到和慢指针一样的位置。
bool hasCycle(ListNode *head)
{
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* fast = head, *slow = &dummy;
    bool res = false;
    while (fast != nullptr && fast->next !=nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            res = true;
            break;
        }
    }
    return res;
}

int main()
{
    ListNode head(3);
	ListNode second(2);
	ListNode third(0);
	ListNode fourth(-4);
    // ListNode fifth(5);
	head.next = &second;
	second.next = &third;
	third.next = &fourth;
    fourth.next = &second;
	bool res = hasCycle(&head);
	std::cout << res << "\n";
    return 0;
}