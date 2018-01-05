#ifndef POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H_
#define POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H_

/*
 * Given a binary tree
 * struct TreeLinkNode {
 *   TreeLinkNode *left;
 *   TreeLinkNode *right;
 *   TreeLinkNode *next;
 * }
 *
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *
 * For example,
 * Given the following perfect binary tree,
 *     1
 *    /  \
 *   2    3
 *  / \  / \
 * 4  5  6  7
 *
 * After calling your function, the tree should look like:
 *  *  1 -> NULL
 *    /  \
 *   2 -> 3 -> NULL
 *  / \  / \
 * 4->5->6->7 -> NULL
 */
#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL) {
			return;
		}
    	queue<TreeLinkNode*> q;
    	q.push(root);
    	while (!q.empty()) {
    		TreeLinkNode* first = NULL;
    		TreeLinkNode* second = NULL;
    		first = q.front();
    		q.pop();
    		int size = q.size();
    		if (first->left != NULL) {
    			q.push(first->left);
    		}
    		if (first->right != NULL) {
    			q.push(first->right);
    		}
    		for (int i = 0; i < size; ++i) {
    			second = q.front();
    			q.pop();
    			first->next = second;
    			first = second;
    			if (first->left != NULL) {
					q.push(first->left);
				}
				if (first->right != NULL) {
					q.push(first->right);
				}
    			second = NULL;
    		}
    		first->next = second;
    	}
    }
};

void Test() {
	TreeLinkNode* node1 = new TreeLinkNode(1);
	TreeLinkNode* node2 = new TreeLinkNode(2);
	TreeLinkNode* node3 = new TreeLinkNode(3);
	TreeLinkNode* node4 = new TreeLinkNode(4);
	TreeLinkNode* node5 = new TreeLinkNode(5);
	TreeLinkNode* node6 = new TreeLinkNode(6);
	TreeLinkNode* node7 = new TreeLinkNode(7);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	Solution S;
	S.connect(node1);
	cout << node2->next->val << endl;
	cout << node6->next->val << endl;
	cout << node1->next << endl;
	cout << node3->next << endl;
	cout << node7->next << endl;
}



#endif /* POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H_ */
