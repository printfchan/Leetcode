/************************************************************************/
/* 
https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
	int minDepth(TreeNode *root) {
		if (root == NULL)
			return 0;
		
		queue<TreeNode*> que[2];
		queue<TreeNode*>* p = NULL;
		queue<TreeNode*>* q = NULL;

		que[0].push(root);
		int level = 1;
		p = &que[(level + 1) & 1];
		q = &que[level& 1];

		while (!p->empty() || !q->empty())
		{
			TreeNode* cur = p->front();
			p->pop();

			if (cur->left == NULL && cur->right == NULL)
				return level;

			if (cur->left != NULL)
			{
				q->push(cur->left);
			}
			if (cur->right != NULL)
			{
				q->push(cur->right);
			}

			if (p->empty())
			{
				level++;
				p = &que[(level + 1) & 1];
				q = &que[level & 1];
			}
		}
		return level;
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
	root->right->right->left = new TreeNode(6);
	
	Solution solution;
	cout << solution.minDepth(root);

	system("pause");
	return 0;
}