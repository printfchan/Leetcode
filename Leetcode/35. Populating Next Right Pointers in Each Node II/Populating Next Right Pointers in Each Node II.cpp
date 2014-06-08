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
		TreeLinkNode* q = NULL;		// ��ŵ�ǰ�ڵ��ͬ��ڵ��е���һ���ڵ㣬��ʼΪ��
		TreeLinkNode* next_level = NULL;	// ��Ÿò�ڵ�ĵ�һ����Ч�ڵ㡣����Ч�ڵ�����һ�εݹ鿪ʼ����ʼ�ڵ�
		// ��ÿһ���ڵ㣬�ٶ��������ڽڵ���Ѿ�������ɣ����ֻҪ�ҵ������ӽڵ㿪ʼ�ݹ鼴��
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