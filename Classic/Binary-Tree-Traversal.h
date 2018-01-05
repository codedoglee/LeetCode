#ifndef BINARY_TREE_TRAVERSAL_H_
#define BINARY_TREE_TRAVERSAL_H_

/*
 * 二叉树的前序、中序、后序遍历，递归和循环实现
 */
#include <stdio.h>
#include <vector>
#include <stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(0), right(0) {}
};

//------------------------------------------------------------------------//
void PreWork(std::vector<int> &vec, TreeNode *root) {
	if (root == 0) {
		return;
	}
	vec.push_back(root->val);
	PreWork(vec, root->left);
	PreWork(vec, root->right);
}

std::vector<int> PreorderTraversal(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	PreWork(result, root);
	return result;
}

std::vector<int> PreorderTraversalIter(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	std::stack<TreeNode *> st;
	TreeNode *cur = root;
	while (cur || !st.empty()) {
		while (cur) {
			result.push_back(cur->val);
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		cur = cur->right;
	}
	return result;
}

void PreorderTraversalTest() {
	TreeNode *root = GetTree();

	std::vector<int> v = PreorderTraversalIter(root);

	for (unsigned int i = 0; i < v.size(); ++i) {
		printf("%d\t", v[i]);
	}
}


//------------------------------------------------------------------------//
void InWork(std::vector<int> &vec, TreeNode *root) {
	if (root == 0) {
		return;
	}
	InWork(vec, root->left);
	vec.push_back(root->val);
	InWork(vec, root->right);
}

std::vector<int> InorderTraversal(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	InWork(result, root);
	return result;
}

std::vector<int> InorderTraversalIter(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	std::stack<TreeNode *> st;
	TreeNode *cur = root;
	while (cur || !st.empty()) {
		while (cur) {
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		result.push_back(cur->val);
		cur = cur->right;
		st.pop();
	}
	return result;
}

void InorderTraversalTest() {
	TreeNode *root = GetTree();

	std::vector<int> v = InorderTraversalIter(root);

	for (unsigned int i = 0; i < v.size(); ++i) {
		printf("%d\t", v[i]);
	}
}


//------------------------------------------------------------------------//
void PostWork(std::vector<int> &vec, TreeNode *root) {
	if (root == 0) {
		return;
	}
	PostWork(vec, root->left);
	PostWork(vec, root->right);
	vec.push_back(root->val);
}

std::vector<int> PostorderTraversal(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	PostWork(result, root);
	return result;
}

std::vector<int> PostorderTraversalIter(TreeNode *root) {
	std::vector<int> result;
	if (root == 0) {
		return result;
	}
	std::stack<TreeNode *> st;
	st.push(root);
	TreeNode *pre = 0;		// 上一个访问输出的结点
	TreeNode *cur = 0;		// 当前结点
	while (!st.empty()) {
		cur = st.top();		// 当前结点为栈顶
		/**
		 * 如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，
		 * 则直接输出该节点，将其出栈，将其设为上一个访问的节点
		 */
		if ((cur->left == 0 && cur->right == 0) || (pre != 0 && (cur->left == pre || cur->right == pre))) {
			result.push_back(cur->val);
			st.pop();
			pre = cur;
		}
		//如果不满足上面两种情况，则将其右孩子左孩子依次入栈
		else {
			if(cur->right)
				st.push(cur->right);
			if(cur->left)
				st.push(cur->left);
		}
	}
	return result;
}



TreeNode *GetTree() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->right = n6;
	n5->left = n7;

	return n1;
}

void PostorderTraversalTest() {
	TreeNode *root = GetTree();

	std::vector<int> v = PostorderTraversalIter(root);

	for (unsigned int i = 0; i < v.size(); ++i) {
		printf("%d\t", v[i]);
	}
}


#endif
