// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。

#include <iostream>
#include <unordered_set>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, struct ListNode* next): val(x), next(next) {};
};

ListNode *detectCycleHash(ListNode *head) 
{
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    std::unordered_set<ListNode*> nodeset;
    ListNode* cur = head;
    while (cur != nullptr) {
        if (nodeset.find(cur) != nodeset.end()) {
            return cur;
        }
        nodeset.insert(cur);
        cur = cur->next;
    }
    return nullptr;
}


ListNode *detectCycle(ListNode *head) 
{
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode* slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            ListNode* newhead = head;
            while (newhead != slow) {
                newhead = newhead->next;
                slow = slow->next;
            }
            return slow;
        }
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
    ListNode list1(3);
	ListNode second(2);
	ListNode third(0);
    ListNode fourth(-4);
	list1.next = &second;
	second.next = &third;
    third.next = &fourth;
    fourth.next = &second;

	ListNode* node = detectCycle(&list1);
	std::cout << node->val << "\n";
    return 0;
}