#ifndef POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H_
#define POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H_

/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous solution still work?
 * Note:
 * You may only use constant extra space.
 *
 * For example,
 * Given the following binary tree,
 *		  1
 *       /  \
 *      2    3
 *     / \    \
 *    4   5    7
 *
 * After calling your function, the tree should look like:
 *        1 -> NULL
 *       /  \
 *      2 -> 3 -> NULL
 *     / \    \
 *    4-> 5 -> 7 -> NULL
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


#endif /* POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H_ */
