/************************************************************************/
/* 
https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
	int maxNum(int x, int y)
	{
		if (x > y)
			return x;
		return y;		
	}

	int maxDepth(TreeNode *root) {
		if (root == NULL)
			return 0;

		return maxNum(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main()
{
	TreeNode *root = NULL;
	Solution solution;
	cout << solution.maxDepth(root);

	system("pause");
	return 0;
}