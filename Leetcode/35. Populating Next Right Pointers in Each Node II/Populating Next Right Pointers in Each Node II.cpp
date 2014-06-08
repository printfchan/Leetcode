/************************************************************************/
/* 
https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:
     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;

		TreeLinkNode* p = root;
		TreeLinkNode* q = NULL;		// 存放当前节点的同层节点中的上一个节点，起始为空
		TreeLinkNode* next_level = NULL;	// 存放该层节点的第一个有效节点。该有效节点是下一次递归开始的起始节点
		// 对每一个节点，假定其所有邻节点均已经计算完成，因此只要找到最左子节点开始递归即可
		while (p != NULL)
		{
			if (p->left != NULL)
			{
				if (q != NULL)
					q->next = p->left;
				q = p->left;
				if (next_level == NULL)
					next_level = p->left;
			}
			if (p->right != NULL)
			{
				if (q != NULL)
					q->next = p->right;
				q = p->right;
				if (next_level == NULL)
					next_level = p->right;
			}
			p = p->next;
		}
		connect(next_level);
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
	//root->right->right = new TreeLinkNode(7);

	Solution solution;
	solution.connect(root);

	system("pause");
	return 0;
}