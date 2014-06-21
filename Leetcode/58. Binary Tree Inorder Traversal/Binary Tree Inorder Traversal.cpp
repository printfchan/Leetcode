/************************************************************************/
/* 
https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,3,2].
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
	vector<int> inorderDFS(TreeNode* root)
	{
		vector<int> res;
		if (!root)
			return res;
		
		vector<int> left = inorderDFS(root->left);
		res.insert(res.end(), left.begin(), left.end());
		res.push_back(root->val);
		vector<int> right = inorderDFS(root->right);
		res.insert(res.end(),right.begin(), right.end());
		return res;
	}

	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		if (!root)
			return res;

		res = inorderDFS(root);
		return res;
	}
};

int main()
{
	TreeNode *root = NULL;
	Solution solution;
	solution.inorderTraversal(root);

	system("pause");
	return 0;
}