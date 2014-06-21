/************************************************************************/
/* 
https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
	[3],
	[20,9],
	[15,7]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		
		vector<int> item;

		vector<TreeNode *> left2right;
		vector<TreeNode *> right2left;

		left2right.push_back(root);
		while (!left2right.empty())
		{
			while (!left2right.empty())
			{
				TreeNode *cur = left2right.back();
				left2right.pop_back();

				item.push_back(cur->val);
				if (cur->left)
					right2left.push_back(cur->left);
				if (cur->right)
					right2left.push_back(cur->right);
			}
			result.push_back(item);
			item.clear();

			while (!right2left.empty())
			{
				TreeNode *cur = right2left.back();
				right2left.pop_back();

				item.push_back(cur->val);
				if (cur->right)
					left2right.push_back(cur->right);
				if (cur->left)
					left2right.push_back(cur->left);
			}
			if (!item.empty())
				result.push_back(item);
			item.clear();
		}
		return result;
	}
};

int main()
{
	TreeNode *root = NULL;
	Solution solution;
	vector<vector<int>> result = solution.zigzagLevelOrder(root);

	system("pause");
	return 0;
}