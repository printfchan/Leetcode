/************************************************************************/
/* 
https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
Given a binary tree

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
     1
   /   \
  2     3
 / \   / \
4   5 6   7
After calling your function, the tree should look like:
      1 -> NULL
   /    \
  2  ->  3 -> NULL
 / \    / \
4-> 5->6-> 7 -> NULL
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//class Solution {
//public:
//	void connect(TreeLinkNode *root) {
//		if (root == NULL || (root->left == NULL && root->right == NULL))
//			return;
//
//		root->left->next = root->right;
//		root->right->next = (root->next == NULL ? NULL : root->next->left);
//		connect(root->left);
//		connect(root->right);
//	}
//};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return;

		queue<TreeLinkNode*> level;
		level.push(root);
		while (!level.empty())
		{
			TreeLinkNode* cur = level.front();
			level.pop();

			if (cur->left != NULL)
			{
				cur->left->next = cur->right;
				cur->right->next = (cur->next == NULL ? NULL : cur->next->left);
				level.push(cur->left);
				level.push(cur->right);
			}
		}
	}
};

int main()
{
	TreeLinkNode *root = NULL;
	root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);

	Solution solution;
	solution.connect(root);

	system("pause");
	return 0;
}