/************************************************************************/
/* 
https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Given inorder and postorder traversal of a tree, construct the binary tree.

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
	TreeNode *buildSubTree(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend)
	{
		TreeNode * root = NULL;
		if (postend < poststart)
			return NULL;
		root = new TreeNode(postorder[postend]);
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		for (int i = instart; i <= inend; ++i)
		{
			if (postorder[postend] == inorder[i])
			{
				left = buildSubTree(inorder, instart, i - 1, postorder, poststart, poststart + (i-1-instart));
				right = buildSubTree(inorder, i + 1, inend, postorder, poststart + (i - 1 - instart) + 1, postend- 1);
				root->left = left;
				root->right = right;
				return root;
			}
		}
		
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode* root = NULL;
		if (inorder.size() == 0 || postorder.size() == 0)
			return root;
		
		root = buildSubTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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