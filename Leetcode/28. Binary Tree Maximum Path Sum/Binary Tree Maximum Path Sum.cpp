/************************************************************************/
/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3
Return 6.
*/
/************************************************************************/

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
	int max_path = INT_MIN;
	int maxPathSum(TreeNode *root) {
		if (root == NULL)
		{
			return 0;
		}

		max_path = root->val;
		DFS(root);

		return max_path;
	}
	int DFS(TreeNode *root)
	{
		if (root->val > max_path)
		{
			max_path = root->val;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return root->val;
		}

		int left = 0, right = 0;
		if (root->left != NULL)
		{
			left = DFS(root->left);
		}

		if (root->right != NULL)
		{
			right = DFS(root->right);
		}

		int max_sub = (left > right ? left : right);

		// max_path = max{root->val + [left > 0] + [right > 0]}
		int sum = root->val;
		if (left > 0)
		{
			sum += left;
		}
		if (right > 0)
		{
			sum += right;
		}
		if (sum > max_path)
		{
			max_path = sum;
		}
		
		// max_root = {root->val + max{root->left, root->right} > 0? max{root->left, root->right}: 0}
		return root->val + (max_sub > 0 ? max_sub : 0);
	}
};

int main()
{
	TreeNode *root = NULL;
	root = new TreeNode(1);
	root->left = new TreeNode(4);
	root->right = new TreeNode(1);
	//root->right->left = new TreeNode(4);

	Solution solution;
	cout << solution.maxPathSum(root);

	system("pause");
	return 0;
}