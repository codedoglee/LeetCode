#ifndef COPY_LIST_WITH_RANDOM_POINTER_H_
#define COPY_LIST_WITH_RANDOM_POINTER_H_

/*
 * A linked list is given such that each node contains an additional random pointer which could point to
 * any node in the list or null. Return a deep copy of the list.
 */
#include <map>
#include <iostream>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	RandomListNode* pNode = head;
    	while (pNode != 0) {
    		RandomListNode* node = new RandomListNode(pNode->label);
    		node->next = pNode->next;
    		pNode->next = node;
    		pNode = node->next;
    	}
    	pNode = head;
    	while (pNode != 0) {
    		if (pNode->random != 0) {
    			pNode->next->random = pNode->random->next;
    		}
    		pNode = pNode->next->next;
    	}
    	pNode = head;
    	RandomListNode* pCloneHead = 0;
    	RandomListNode* pCloneNode = 0;
    	if (pNode != 0) {
    		pCloneHead = pNode->next;
    		pCloneNode = pNode->next;
    		pNode->next = pCloneNode->next;
    		pNode = pNode->next;
    	}
    	while (pNode != 0) {
    		pCloneNode->next = pNode->next;
    		pCloneNode = pCloneNode->next;
    		pNode->next = pCloneNode->next;
    		pNode = pNode->next;
    	}
    	return pCloneHead;
    }
};

RandomListNode *GetComplexList() {
	RandomListNode *n1 = new RandomListNode(1);
	RandomListNode *n2 = new RandomListNode(2);
	RandomListNode *n3 = new RandomListNode(3);
	RandomListNode *n4 = new RandomListNode(4);
	RandomListNode *n5 = new RandomListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	n1->random = n3;
	n2->random = n5;
	n4->random = n1;

	return n1;
}

void Test() {
	RandomListNode* head = GetComplexList();
	Solution st;
	RandomListNode* newHead = st.copyRandomList(head);
	printf("原始链表：");
	while (head) {
		printf("(%d,%d)  ", head->label, head->random == 0 ? 0 : head->random->label);
		head = head->next;
	}
	printf("\n克隆链表：");
	while (newHead) {
		printf("(%d,%d)  ", newHead->label, newHead->random == 0 ? 0 : newHead->random->label);
		newHead = newHead->next;
	}
}



#endif /* COPY_LIST_WITH_RANDOM_POINTER_H_ */
