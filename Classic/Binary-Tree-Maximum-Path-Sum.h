#ifndef BINARY_TREE_MAXIMUM_PATH_SUM_H_
#define BINARY_TREE_MAXIMUM_PATH_SUM_H_

/*
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 * For example:
 * Given the below binary tree,
 * 	   1
 * 	  / \
 * 	 2   3
 * Return 6.
 */
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode *root) {
    	if (root == 0) {
    		return 0;
    	}
    	queue<TreeNode*> q;
    	q.push(root);
    	int max = root->val;
    	while (!q.empty()) {
    		TreeNode *node = q.front();
    		q.pop();
    		int left = maxPathSumCore(node->left);
    		int right = maxPathSumCore(node->right);
    		int cur = node->val;
    		if (left > 0) {
    			cur += left;
    		}
    		if (right > 0) {
    			cur += right;
    		}
    		if (cur > max) {
    			max = cur;
    		}
    		if (node->left != 0) {
    			q.push(node->left);
    		}
    		if (node->right != 0) {
    			q.push(node->right);
    		}
    	}
    	return max;
    }

    int maxPathSumCore(TreeNode *node) {
    	if (node == 0) {
    		return 0;
    	}
    	int left = maxPathSumCore(node->left);
    	int right = maxPathSumCore(node->right);
    	int max = node->val;
    	int bigger = left >= right ? left : right;
    	if (bigger > 0) {
    		max += bigger;
    	}
    	return max;
    }
};



#endif /* BINARY_TREE_MAXIMUM_PATH_SUM_H_ */
