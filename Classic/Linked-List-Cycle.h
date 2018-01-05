#ifndef LINKED_LIST_CYCLE_H_
#define LINKED_LIST_CYCLE_H_

/*
 * Given a linked list, determine if it has a cycle in it.
 * Follow up: Can you solve it without using extra space?
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == 0 || head->next == 0) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != 0 && fast->next != 0) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};



#endif /* LINKED_LIST_CYCLE_H_ */
