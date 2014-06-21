/************************************************************************/
/* 
https://oj.leetcode.com/problems/validate-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void inSearch(TreeNode *root, TreeNode *&prev, bool& isValid)
	{
		if (root == NULL)
			return;

		inSearch(root->left, prev, isValid);
		if (prev != NULL)
		{
			if (root->val <= prev->val)
			{
				isValid = false;
				return;
			}
		}
		prev = root;
		inSearch(root->right, prev, isValid);
	}

	bool isValidBST(TreeNode *root) {
		if (!root)
			return true;
		if (root->left == NULL && root->right == NULL)
			return true;
		bool isValid = true;
		TreeNode *prev = NULL;
		inSearch(root, prev, isValid);
		return isValid;
	}
};

int main()
{
	TreeNode *root = NULL;
	root = new TreeNode(1);
	root->left = new TreeNode(1);

	Solution solution;
	cout << solution.isValidBST(root);

	system("pause");
	return 0;
}