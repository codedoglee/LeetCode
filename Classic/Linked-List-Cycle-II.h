#ifndef LINKED_LIST_CYCLE_II_H_
#define LINKED_LIST_CYCLE_II_H_

/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up: Can you solve it without using extra space?
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == 0 || head->next == 0) {
            return 0;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != 0 && fast->next != 0) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (slow != fast) {
            return 0;
        }
        ListNode* pEntry = head;
        while (pEntry != slow) {
            pEntry = pEntry->next;
            slow = slow->next;
        }
        return pEntry;
    }
};



#endif /* LINKED_LIST_CYCLE_II_H_ */
