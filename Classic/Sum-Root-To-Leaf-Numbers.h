#ifndef SUM_ROOT_TO_LEAF_NUMBERS_H_
#define SUM_ROOT_TO_LEAF_NUMBERS_H_

/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 * 	   1
 *    / \
 *   2   3
 *
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 */
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	long long sum = 0;
	long long cur = 0;
    int sumNumbers(TreeNode *root) {
    	if (root == 0) {
			return 0;
		}
    	dfs(root);
    	return sum;
    }
    void dfs(TreeNode *parent) {
    	cur = cur * 10 + parent->val;
    	if (parent->left == 0 && parent->right == 0) {
    		sum += cur;
    	}
    	else {
    		if (parent->left != 0) {
    			dfs(parent->left);
    			cur /= 10;
    		}
    		if (parent->right != 0) {
    			dfs(parent->right);
    			cur /= 10;
    		}
    	}
    }
};


#endif /* SUM_ROOT_TO_LEAF_NUMBERS_H_ */
