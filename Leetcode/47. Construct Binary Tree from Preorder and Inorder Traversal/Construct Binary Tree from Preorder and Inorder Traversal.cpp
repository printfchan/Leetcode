/************************************************************************/
/*
https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
	TreeNode *buildSubTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend)
	{
		TreeNode * root = NULL;
		if (preend < prestart || inend < instart)
			return NULL;

		root = new TreeNode(preorder[prestart]);
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		for (int i = instart; i <= inend; ++i)
		{
			if (preorder[prestart] == inorder[i])
			{
				left = buildSubTree(preorder, prestart + 1, prestart + (i - instart), inorder, instart, i-1);
				right = buildSubTree(preorder, prestart + (i - instart) + 1, preend, inorder, i+1, inend);
				root->left = left;
				root->right = right;
				return root;
			}
		}

	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		TreeNode* root = NULL;

		root = buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		return root;
	}
};

int main()
{
	vector<int> inorder;
	vector<int> postorder;
	Solution solution;
	solution.buildTree(inorder, postorder);

	system("pause");
	return 0;
}