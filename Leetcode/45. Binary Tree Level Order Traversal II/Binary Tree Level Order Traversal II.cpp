/************************************************************************/
/* 
https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    / \
   15  7 
return its bottom-up level order traversal as:
[
	[15,7],
	[9,20],
	[3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
    1
   / \
  2   3
	 /
	4
	 \
	  5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}"
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
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		if (!root)
			return result;

		queue<TreeNode*> que;
		que.push(root);
		que.push(NULL);

		vector<int> item;

		while (!que.empty())
		{
			TreeNode* cur = que.front();
			que.pop();
			if (cur == NULL)
			{
				if (!item.empty())
				{
					result.push_back(item);
					item.clear();
					que.push(NULL);
				}
			}
			else {
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
				item.push_back(cur->val);
			}	
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	TreeNode *root = NULL;
	root = new TreeNode(1);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(5);

	Solution solution;
	vector<vector<int>> result = solution.levelOrderBottom(root);

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