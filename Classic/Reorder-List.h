#ifndef REORDER_LIST_H_
#define REORDER_LIST_H_

/*
 * Given a singly linked list L: L0 -> L1 -> ... -> Ln-1 -> Ln,
 * reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 * You must do this in-place without altering the node's value.
 * For example, Given{1,2,3,4}, reorder it to{1,4,2,3}.
 */

#include <stdio.h>
#include <stack>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

ListNode *GetList() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	return n1;
}

void ReorderList(ListNode *head) {
	if (head == 0 || head->next == 0 || head->next->next == 0) {
		return;
	}
	ListNode *head1 = head;
	ListNode *slow = head->next;
	ListNode *fast = head->next->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *head2 = slow->next;
	slow->next = 0;

	ListNode *left = 0;
	ListNode *middle = head2;
	ListNode *right = head2->next;
	while (right) {
		middle->next = left;
		left = middle;
		middle = right;
		right = right->next;
	}
	middle->next = left;
	head2 = middle;

	ListNode *back1 = head1->next;
	ListNode *back2 = head2->next;
	while (back1 && back2) {
		head1->next = head2;
		head2->next = back1;
		head1 = back1;
		head2 = back2;
		back1 = back1->next;
		back2 = back2->next;
	}
	head1->next = head2;
	head2->next = back1;
}

void ReorderListTest() {
	ListNode *head = GetList();
	ReorderList(head);

	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}
}


#endif
