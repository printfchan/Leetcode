/************************************************************************/
/* 
https://oj.leetcode.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
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
	int height(int a, int b)
	{
		return (a > b ? a : b);
	}

	int heightDFS(TreeNode *root, bool& bBalance)
	{
		if (!bBalance)
			return -1;

		if (root == NULL)
			return 0;

		int left = 0;
		if (root->left != NULL)
		{
			left = heightDFS(root->left, bBalance);
			if (left == -1)
				return -1;
		}
		
		int right= 0;
		if (root->right != NULL)
		{
			right = heightDFS(root->right, bBalance);
			if (right == -1)
				return -1;
		}

		if (abs(left - right) > 1)
			bBalance = false;

		return height(left, right) + 1;
	}

	bool isBalanced(TreeNode *root) {
		if (root == NULL)
			return true;

		bool bBalance = true;
		heightDFS(root, bBalance);
		return bBalance;
	}
};

int main()
{
	TreeNode* root = NULL;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	//root->right->right->left = new TreeNode(6);

	Solution solution;
	cout << solution.isBalanced(root);

	system("pause");
	return 0;
}