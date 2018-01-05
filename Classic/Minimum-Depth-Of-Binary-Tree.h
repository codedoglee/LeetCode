/*
 * Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest
 * path from the root node down to the nearest leaf node.
 */

#include <stdio.h>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) { val = x; left = 0; right = 0; }
};

class Solution {
public:
    int run(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left) {
        	return run(root->right) + 1;
        }
        else if (!root->right) {
        	return run(root->left) + 1;
        }
        else {
        	return std::min(run(root->left), run(root->right)) + 1;
        }
    }
};
