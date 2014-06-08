/************************************************************************/
/* 
https://oj.leetcode.com/problems/path-sum-ii/
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
return
[
	[5,4,11,2],
	[5,8,4,5]
]
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
	void DFS(TreeNode *root, int sum, vector<vector<int>>& result, vector<int>& item)
	{
		if (root == NULL)
			return;

		if (root->left == NULL && root->right == NULL)
		{
			if (root->val == sum)
			{
				item.push_back(root->val);
				result.push_back(item);
				item.pop_back();
			}
			return;
		}
		item.push_back(root->val);
		DFS(root->left, sum - root->val, result, item);
		DFS(root->right, sum - root->val, result, item);
		item.pop_back();

		return ;
	}

	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<vector<int>> result;
		vector<int> item;

		DFS(root, sum, result, item);

		return result;
	}
};

int main()
{
	TreeNode* root = NULL;
	root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	Solution solution;
	vector<vector<int>> result = solution.pathSum(root, 22);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}