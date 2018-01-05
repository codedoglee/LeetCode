#ifndef SORT_LIST_H_
#define SORT_LIST_H_

/*
 * Sort a linked list
 */

#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

void Swap(int *u, int *v) {
	int temp = *u;
	*u = *v;
	*v = temp;
}

ListNode *GetList() {
	ListNode *n1 = new ListNode(3);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(5);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	return n1;
}

ListNode *PartitionList(ListNode *left, ListNode *right) {
	if (left == right || left->next == right) {
		return left;
	}
	int y = left->val;
	ListNode *p = left;
	for (ListNode *q = left->next; q != right; q = q->next) {
		if (q->val < y) {
			p = p->next;
			Swap(&(p->val), &(q->val));
		}
	}
	Swap(&(p->val), &(left->val));
	return p;
}

void QuickSortList(ListNode *left, ListNode *right) {
	if (left == right || left->next == right) {
		return;
	}
	ListNode *mid = PartitionList(left, right);
	QuickSortList(left, mid);
	QuickSortList(mid->next, right);
}

void QuickSortListTest() {
	ListNode *head = GetList();

	QuickSortList(head, 0);

	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}
}


//------------------------------------------------------------------------//
ListNode *GetMid(ListNode *head) {
	if (head == 0 || head->next == 0) {
		return head;
	}
	ListNode *pre = head;	// pre->next == slow
	ListNode *slow = head->next;
	ListNode *fast = head->next->next;
	while (fast && fast->next) {
		pre = pre->next;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = 0;	// 将链表分为两段
	return slow;
}

ListNode* MergeList(ListNode* head1, ListNode* head2) {
	ListNode *newHead = new ListNode(0);
	ListNode *newTail = newHead;
	while (head1 && head2) {
		if (head1->val <= head2->val) {
			newTail->next = head1;
			head1 = head1->next;
		}
		else {
			newTail->next = head2;
			head2 = head2->next;
		}
		newTail = newTail->next;
	}
	if (head1) {
		newTail->next = head1;
	}
	if (head2) {
		newTail->next = head2;
	}
	return newHead->next;
}

ListNode *MergeSortList(ListNode *head) {
	if (head == 0 || head->next == 0) {
		return head;
	}
	ListNode* head1 = head;
	ListNode* head2 = GetMid(head);

	// 分别对两段链表进行排序
	head1 = MergeSortList(head1);
	head2 = MergeSortList(head2);

	return MergeList(head1, head2);
}

void MergeSortListTest() {
	ListNode *head = GetList();

	head = MergeSortList(head);

	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}
}


//------------------------------------------------------------------------//
ListNode *InsertionSortList(ListNode *head) {
	if (head == 0 || head->next == 0) {
		return head;
	}
	ListNode *preTemp = 0;
	ListNode *temp = 0;
	ListNode *preCur = head;
	ListNode *cur = head->next;
	while (cur) {
		preTemp = 0;
		temp = head;
		while (temp != cur && temp->val <= cur->val) {
			preTemp = temp;
			temp = temp->next;
		}
		if (temp == head) {
			preCur->next = cur->next;
			cur->next = head;
			head = cur;
		}
		else if (temp == cur) {
			preCur = cur;
			cur = cur->next;
		}
		else {
			preCur->next = cur->next;
			preTemp->next = cur;
			cur->next = temp;
		}
		cur = preCur->next;
	}
	return head;
}

void InsertionSortListTest() {
	ListNode *head = GetList();

	head = InsertionSortList(head);

	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}
}

#endif
